//
// Created by Иван Лескин on 14/04/2023.
//

#include <cstdarg>
#include "IR.h"
#include "utils/PStack.h"

void IR::Visit(std::shared_ptr<Program> program) {
    program->class_decl_list->Accept(shared_from_this());
    program->main_class->Accept(shared_from_this());
}

void IR::Visit(std::shared_ptr<ClassMain> main_class) {
    main_class->statements_list->Accept(shared_from_this());
}

void IR::Visit(std::shared_ptr<AssertStmt> assert_stmt) {
    assert_stmt->expression->Accept(shared_from_this());
    auto val = program_stack.PopBack();
    assert(val);
}

void IR::Visit(std::shared_ptr<LocalVarDeclStmt> local_var_decl_stmt) {
    local_var_decl_stmt->Accept(shared_from_this());
}

void IR::Visit(std::shared_ptr<StmtListStmt> stmt_list_stmt) {
    stmt_list_stmt->Accept(shared_from_this());
}

void IR::Visit(std::shared_ptr<If> if_stmt) {
    program_stack.Pop();

    // current function object
    auto function = builder->GetInsertBlock()->getParent();

    // condition value
    if_stmt->expression->Accept(shared_from_this());
    auto cond = program_stack.PopBack();

    // condition empty??
    if (!cond) {
        program_stack.Push(nullptr);
        return;
    }

    cond = builder->CreateFCmpONE(
            cond,
            llvm::ConstantFP::get(*context, llvm::APFloat(0.0)),
            "ifcond"
    );

    auto then_bb = llvm::BasicBlock::Create(
            *context,
            "then",
            function
    );

    auto else_bb = llvm::BasicBlock::Create(
            *context,
            "else"
    );

    // for SSA form of IR
    auto merge_bb = llvm::BasicBlock::Create(
            *context,
            "ifcont"
    );

    builder->CreateCondBr(cond, then_bb, else_bb);

    // emit then value
    builder->SetInsertPoint(then_bb);

    // evaluate then value
    if_stmt->statement->Accept(shared_from_this());
    auto then_val = program_stack.PopBack();
    if (!then_val) {
        program_stack.Push(nullptr);
        return;
    }

    builder->CreateBr(merge_bb);

    // codegen of 'then' can change the current block, update then_bb for the PHI
    then_bb = builder->GetInsertBlock();

    // The basic issue is that when we create the Phi node in the merge block,
    // we need to set up the block/value pairs that indicate how the Phi will work.
    // Importantly, the Phi node expects to have an entry for each predecessor of the block in the CFG.
    // Why then, are we getting the current block when we just set it to ThenBB 5 lines above?
    // The problem is that the “Then” expression may actually itself change the block that
    // the Builder is emitting into if, for example, it contains a nested “if/then/else”
    // expression. Because calling codegen() recursively could arbitrarily change the notion
    // of the current block, we are required to get an up-to-date value for code that will set up the Phi node.
    function->getBasicBlockList().push_back(else_bb);
    builder->SetInsertPoint(else_bb);
    builder->CreateBr(merge_bb);
//    there is no else block here
//    else_bb = builder->GetInsertBlock();
//    emit merge block
    function->getBasicBlockList().push_back(merge_bb);
    builder->SetInsertPoint(merge_bb);
    program_stack.Push(merge_bb);
}

void IR::Visit(std::shared_ptr<IfElse> if_else_stmt) {
    program_stack.Pop();

    // current function object
    auto function = builder->GetInsertBlock()->getParent();

    // condition value
    if_else_stmt->expression->Accept(shared_from_this());
    auto cond = program_stack.PopBack();

    // condition empty??
    if (!cond) {
        program_stack.Push(nullptr);
        return;
    }

    cond = builder->CreateFCmpONE(
            cond,
            llvm::ConstantFP::get(*context, llvm::APFloat(0.0)),
            "ifcond"
    );

    auto then_bb = llvm::BasicBlock::Create(
            *context,
            "then",
            function
    );

    auto else_bb = llvm::BasicBlock::Create(
            *context,
            "else"
    );

    // for SSA form of IR
    auto merge_bb = llvm::BasicBlock::Create(
            *context,
            "ifcont"
    );

    builder->CreateCondBr(cond, then_bb, else_bb);

    // emit then value
    builder->SetInsertPoint(then_bb);

    // evaluate then value
    if_else_stmt->stmt_true->Accept(shared_from_this());
    auto then_val = program_stack.PopBack();
    if (!then_val) {
        program_stack.Push(nullptr);
        return;
    }

    builder->CreateBr(merge_bb);

    // codegen of 'then' can change the current block, update then_bb for the PHI
    then_bb = builder->GetInsertBlock();

    // The basic issue is that when we create the Phi node in the merge block,
    // we need to set up the block/value pairs that indicate how the Phi will work.
    // Importantly, the Phi node expects to have an entry for each predecessor of the block in the CFG.
    // Why then, are we getting the current block when we just set it to ThenBB 5 lines above?
    // The problem is that the “Then” expression may actually itself change the block that
    // the Builder is emitting into if, for example, it contains a nested “if/then/else”
    // expression. Because calling codegen() recursively could arbitrarily change the notion
    // of the current block, we are required to get an up-to-date value for code that will set up the Phi node.
    function->getBasicBlockList().push_back(else_bb);
    builder->SetInsertPoint(else_bb);
    builder->CreateBr(merge_bb);
    else_bb = builder->GetInsertBlock();
//    emit merge block
    function->getBasicBlockList().push_back(merge_bb);
    builder->SetInsertPoint(merge_bb);

    if_else_stmt->stmt_false->Accept(shared_from_this());
    auto else_val = program_stack.PopBack();
    if (!else_val) {
        program_stack.Push(nullptr);
        return;
    }

    builder->CreateBr(merge_bb);

    // update for phi
    else_bb = builder->GetInsertBlock();

    function->getBasicBlockList().push_back(merge_bb);
    builder->SetInsertPoint(merge_bb);
    auto phi = builder->CreatePHI(llvm::Type::getDoubleTy(*context), 2, "iftmp");

    phi->addIncoming(then_val, then_bb);
    phi->addIncoming(else_val, else_bb);

    program_stack.Push(phi);
}

void IR::Visit(std::shared_ptr<While> while_stmt) {
    program_stack.Pop();

    auto function = builder->GetInsertBlock()->getParent();

    auto cond_bb = llvm::BasicBlock::Create(*context, "wcond");
    function->getBasicBlockList().push_back(cond_bb);
    auto body_bb = llvm::BasicBlock::Create(*context, "wbody");
    function->getBasicBlockList().push_back(body_bb);
    auto merge_bb = llvm::BasicBlock::Create(*context, "merge");
    function->getBasicBlockList().push_back(merge_bb);

    builder->CreateBr(cond_bb);
    builder->SetInsertPoint(cond_bb);

    // condition value
    while_stmt->expression->Accept(shared_from_this());
    auto cond = program_stack.PopBack();

    // condition empty??
    if (!cond) {
        program_stack.Push(nullptr);
        return;
    }

    cond = builder->CreateFCmpONE(
            cond,
            llvm::ConstantFP::get(*context, llvm::APFloat(0.0)),
            "whilecond"
    );

    builder->CreateCondBr(cond, body_bb, merge_bb);

    builder->SetInsertPoint(body_bb);

    // re-evaluate
    while_stmt->statement->Accept(shared_from_this());

    builder->CreateBr(cond_bb);
    builder->SetInsertPoint(merge_bb);

    program_stack.Push(merge_bb);
}

void IR::Visit(std::shared_ptr<PrintStmt> print_stmt) {
    program_stack.Pop();

    std::string string = "%d\n";
    llvm::Constant* fmt = llvm::ConstantDataArray::getString(*context, string);

    llvm::AllocaInst* alloca = builder->CreateAlloca(fmt->getType());
    builder->CreateStore(fmt, alloca);

    // cast string to char*
    llvm::Value* formatted_string = builder->CreateBitCast(alloca, builder->getInt8PtrTy());
    print_stmt->expression->Accept(shared_from_this());
    llvm::Value* pointer = program_stack.PopBack();

    llvm::LoadInst* value = builder->CreateLoad(builder->getInt32Ty(), pointer);

    llvm::PointerType* pointer_type = builder->getInt8PtrTy();

    llvm::Function* printf_function = module->getFunction("printf");

    if (printf_function == nullptr) {
        llvm::FunctionType* printf_type = llvm::FunctionType::get(
                builder->getInt32Ty(),
                {pointer_type},
                true
        );

        printf_function = llvm::Function::Create(
                printf_type, llvm::Function::ExternalLinkage,
                "printf",
                *module
        );
    }

    program_stack.Push(builder->CreateCall(printf_function, {formatted_string, value}, "printCall"));
}

llvm::CallInst* IR::ir_print(llvm::Module *mod, llvm::BasicBlock *bb, const char *format, ...) {
    auto func_printf = mod->getFunction("printf");
    if (!func_printf) {
        auto Pty = llvm::PointerType::get(
                llvm::IntegerType::get(mod->getContext(), 8),
                0
                );
        auto FuncTy9 = llvm::FunctionType::get(
                llvm::IntegerType::get(mod->getContext(), 32),
                true
                );

        func_printf = llvm::Function::Create(FuncTy9, llvm::GlobalValue::ExternalLinkage, "printf", mod);
        func_printf->setCallingConv(llvm::CallingConv::C);

        llvm::AttributeList func_printf_PAL;
        func_printf->setAttributes(func_printf_PAL);
    }

    builder->SetInsertPoint(bb);

    auto str = builder->CreateGlobalStringPtr(format);
    std::vector <llvm::Value *> int32_call_params;
    int32_call_params.push_back(str);

    va_list ap;
    va_start(ap, format);

    char *str_ptr = va_arg(ap, char*);
    llvm::Value *format_ptr = builder->CreateGlobalStringPtr(str_ptr);
    int32_call_params.push_back(format_ptr);

    std::vector<llvm::Value*> extra;
    do {
        llvm::Value *op = va_arg(ap, llvm::Value*);
        if (op) {
            int32_call_params.push_back(op);
        } else {
            break;
        }
    } while (1);
    va_end(ap);

    llvm::CallInst * int32_call = llvm::CallInst::Create(func_printf, int32_call_params, "call", bb);
    return int32_call;
}

void IR::Visit(std::shared_ptr<AssignmentStmt> assignment_stmt) {
    assignment_stmt->expr->Accept(shared_from_this());
    namedValues[assignment_stmt->lvalue->name] = program_stack.PopBack();
}

void IR::Visit(std::shared_ptr<BinaryOp> bin_op_expr) {
    bin_op_expr->lhs->Accept(shared_from_this());
    auto lhs_val = program_stack.PopBack();
    bin_op_expr->rhs->Accept(shared_from_this());
    auto rhs_val = program_stack.PopBack();

    llvm::Value *op_res;

    switch (bin_op_expr->op) {

        case BinaryOp::AND:
            op_res = builder->CreateAnd(lhs_val, rhs_val, "tmpAnd");
            program_stack.Push(op_res);
            return;
        case BinaryOp::OR:
            op_res = builder->CreateOr(lhs_val, rhs_val, "tmpOr");
            program_stack.Push(op_res);
            return;
        case BinaryOp::LESS:
            op_res = builder->CreateICmpSLT(lhs_val, rhs_val, "tmpLe");
            program_stack.Push(op_res);
            return;
        case BinaryOp::GREATER:
            op_res = builder->CreateICmpSGT(lhs_val, rhs_val, "tmpGe");
            program_stack.Push(op_res);
            return;
        case BinaryOp::EQUAL:
            op_res = builder->CreateICmpEQ(lhs_val, rhs_val, "tmpEq");
            program_stack.Push(op_res);
            return;
        case BinaryOp::PLUS:
            op_res = builder->CreateFAdd(lhs_val, rhs_val, "tmpAdd");
            program_stack.Push(op_res);
            return;
        case BinaryOp::MINUS:
            op_res = builder->CreateFSub(lhs_val, rhs_val, "tmpSub");
            program_stack.Push(op_res);
            return;
        case BinaryOp::STAR:
            op_res = builder->CreateFMul(lhs_val, rhs_val, "tmpMul");
            program_stack.Push(op_res);
            return;
        case BinaryOp::SLASH:
            op_res = builder->CreateFDiv(lhs_val, rhs_val, "tmpDiv");
            program_stack.Push(op_res);
            return;
        case BinaryOp::MOD:
            op_res = builder->CreateSRem(lhs_val, rhs_val, "tmpRem");
            program_stack.Push(op_res);
            return;
    }
}

void IR::Visit(std::shared_ptr<False> false_expr) {
    auto val = builder->getInt8(0);
    auto mem = builder->CreateAlloca(builder->getInt8Ty());
    builder->CreateAlignedStore(val, mem, 1);
    program_stack.Push(mem);
}

void IR::Visit(std::shared_ptr<True> true_expr) {
    auto val = builder->getInt8(1);
    auto mem = builder->CreateAlloca(builder->getInt8Ty());
    builder->CreateAlignedStore(val, mem, 1);
    program_stack.Push(mem);
}

void IR::Visit(std::shared_ptr<Int> int_expr) {
    auto val = builder->getInt32(int_expr->val);
    auto mem = builder->CreateAlloca(builder->getInt8Ty());
    builder->CreateAlignedStore(val, mem, 1);
    program_stack.Push(mem);
}

void IR::Visit(std::shared_ptr<New> new_expr) {
    ;
}

void IR::Visit(std::shared_ptr<Not> not_expr) {
    not_expr->Accept(shared_from_this());
    auto val = program_stack.PopBack();
    auto llvm_res = builder->CreateNot(val);
    program_stack.Push(llvm_res);
}

void IR::Visit(std::shared_ptr<Id> ident_expr) {
    program_stack.Push(namedValues[ident_expr->keyword]);
}

void IR::Visit(std::shared_ptr<Var> var_decl) {
    auto val = builder->getInt8(0);
    auto mem = builder->CreateAlloca(builder->getInt8Ty());
    builder->CreateAlignedStore(val, mem, 1);

    namedValues[var_decl->name] = mem;
}

void IR::Visit(std::shared_ptr<Lvalue> lvalue) {
    ;
}

int IR::GetResult(std::shared_ptr<Program> program) {
    Visit(std::move(program));
}
