//
// Created by Иван Лескин on 14/04/2023.
//

#include "IR.h"

void IR::Visit(std::shared_ptr<Program> program) {
    program->class_decl_list->Accept(shared_from_this());
    program->main_class->Accept(shared_from_this());
}

void IR::Visit(std::shared_ptr<ClassMain> main_class) {
    main_class->statements_list->Accept(shared_from_this());
}

void IR::Visit(std::shared_ptr<AssertStmt> assert_stmt) {
    assert_stmt->expression->Accept(shared_from_this());
    auto val = program_stack.Pop();
    val.
}

void IR::Visit(std::shared_ptr<LocalVarDeclStmt> local_var_decl_stmt) {

}

void IR::Visit(std::shared_ptr<StmtListStmt> stmt_list_stmt) {

}

void IR::Visit(std::shared_ptr<If> if_stmt) {

}

void IR::Visit(std::shared_ptr<IfElse> if_else_stmt) {

}

void IR::Visit(std::shared_ptr<While> while_stmt) {

}

void IR::Visit(std::shared_ptr<PrintStmt> print_stmt) {

}

void IR::Visit(std::shared_ptr<AssignmentStmt> assignment_stmt) {
    assignment_stmt->expr->Accept(shared_from_this());
    namedValues[assignment_stmt->lvalue->name] = program_stack.Pop();
}

void IR::Visit(std::shared_ptr<BinaryOp> bin_op_expr) {
    bin_op_expr->lhs->Accept(shared_from_this());
    auto lhs_val = program_stack.Pop();
    bin_op_expr->rhs->Accept(shared_from_this());
    auto rhs_val = program_stack.Pop();

    llvm::Value* op_res;

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

}

void IR::Visit(std::shared_ptr<New> new_expr) {

}

void IR::Visit(std::shared_ptr<Not> not_expr) {

}

void IR::Visit(std::shared_ptr<Id> ident_expr) {

}

void IR::Visit(std::shared_ptr<Var> var_decl) {

}

void IR::Visit(std::shared_ptr<Lvalue> lvalue) {

}

int IR::GetResult(std::shared_ptr<Program> program) {
    return 0;
}
