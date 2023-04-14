//
// Created by Иван Лескин on 14/04/2023.
//

#ifndef MINIJAVA_IR_H
#define MINIJAVA_IR_H
#include "utils/forward_include.h"
#include <memory>
#include <unordered_map>
#include <map>

#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "utils/PStack.h"


class IR: public Visitor, public std::enable_shared_from_this<IR> {
    void Visit(std::shared_ptr<Program> program) override;
    void Visit(std::shared_ptr<ClassMain> main_class) override;
    void Visit(std::shared_ptr<AssertStmt> assert_stmt) override;
    void Visit(std::shared_ptr<LocalVarDeclStmt> local_var_decl_stmt) override;
    void Visit(std::shared_ptr<StmtListStmt> stmt_list_stmt) override;
    void Visit(std::shared_ptr<If> if_stmt) override;
    void Visit(std::shared_ptr<IfElse> if_else_stmt) override;
    void Visit(std::shared_ptr<While> while_stmt) override;
    void Visit(std::shared_ptr<PrintStmt> print_stmt) override;
    void Visit(std::shared_ptr<AssignmentStmt> assignment_stmt) override;
    void Visit(std::shared_ptr<BinaryOp> bin_op_expr) override;
    void Visit(std::shared_ptr<True> true_expr) override;
    void Visit(std::shared_ptr<False> false_expr) override;
    void Visit(std::shared_ptr<Int> int_expr) override;
    void Visit(std::shared_ptr<New> new_expr) override;
    void Visit(std::shared_ptr<Not> not_expr) override;
    void Visit(std::shared_ptr<Id> ident_expr) override;
    void Visit(std::shared_ptr<Var> var_decl) override;
    void Visit(std::shared_ptr<Lvalue> lvalue) override;
    int GetResult(std::shared_ptr<Program> program);
private:
    PStack<llvm::Value*> program_stack;
    llvm::LLVMContext* context;
    llvm::IRBuilder<>* builder;
    llvm::Module* module;
    std::map<std::string, llvm::Value *> namedValues;
};


#endif //MINIJAVA_IR_H
