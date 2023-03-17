//
// Created by Иван Лескин on 16/03/2023.
//

#ifndef MINIJAVA_INTERPRETER_H
#define MINIJAVA_INTERPRETER_H
#include "utils/forward_include.h"
#include <memory>
#include <unordered_map>
#include "Visitor.h"

class Interpreter: public Visitor,
                   public std::enable_shared_from_this<Interpreter> {
public:
    Interpreter();

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
    void setTos(int value);
    void reset();

private:
    struct Variable {
        Type type;
        bool is_init = false;
        int value;
    };

    std::unordered_map<std::string, Variable> variables;
    int tos_value_;
    bool is_tos_expression_;

};
#endif //MINIJAVA_INTERPRETER_H
