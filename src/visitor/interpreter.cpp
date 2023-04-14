//
// Created by Иван Лескин on 16/03/2023.
//

#include "interpreter.h"
#include "expressions/BinaryOp.h"
#include <utility>
class AssertionFault: public std::exception {};
class UnknownOperator: public std::exception {};

void Interpreter::Visit(std::shared_ptr<Program> program) {
    program->class_decl_list->Accept(shared_from_this());
    program->main_class->Accept(shared_from_this());
}

void Interpreter::Visit(std::shared_ptr<ClassMain> main_class) {
    main_class->statements_list->Accept(shared_from_this());
}

void Interpreter::Visit(std::shared_ptr<AssertStmt> assert_stmt) {
    assert_stmt->expression->Accept(shared_from_this());
    if (!tos_value_) {
        throw AssertionFault();
    }
}

void Interpreter::Visit(std::shared_ptr<LocalVarDeclStmt> local_var_decl_stmt) {
    local_var_decl_stmt->var_decl->Accept(shared_from_this());
}

void Interpreter::Visit(std::shared_ptr<StmtListStmt> stmt_list_stmt) {
    stmt_list_stmt->statement_list->Accept(shared_from_this());
}

void Interpreter::Visit(std::shared_ptr<If> if_stmt) {
    if_stmt->expression->Accept(shared_from_this());
    if (tos_value_) {
        if_stmt->statement->Accept(shared_from_this());
    }
}

void Interpreter::Visit(std::shared_ptr<IfElse> if_else_stmt) {
    if_else_stmt->expression->Accept(shared_from_this());
    int val = tos_value_;
    if (val) {
        if_else_stmt->stmt_true->Accept(shared_from_this());
    } else {
        if_else_stmt->stmt_false->Accept(shared_from_this());
    }
}

void Interpreter::Visit(std::shared_ptr<While> while_stmt) {
    while_stmt->expression->Accept(shared_from_this());
    int val = tos_value_;
    while(val) {
        while_stmt->statement->Accept(shared_from_this());
        while_stmt->expression->Accept(shared_from_this());
        val = tos_value_;
    }
}

void Interpreter::Visit(std::shared_ptr<PrintStmt> print_stmt) {
    print_stmt->expression->Accept(shared_from_this());
    reset();
}

void Interpreter::Visit(std::shared_ptr<AssignmentStmt> assignment_stmt) {
    assignment_stmt->expr->Accept(shared_from_this());
    variables[assignment_stmt->lvalue->name].is_init = true;
    variables[assignment_stmt->lvalue->name].value = tos_value_;
}

void Interpreter::Visit(std::shared_ptr<BinaryOp> bin_op_expr) {
    bin_op_expr->lhs->Accept(shared_from_this());
    int lhs_val = tos_value_;
    bin_op_expr->rhs->Accept(shared_from_this());
    int rhs_val = tos_value_;

    int res = 0;

    switch (bin_op_expr->op) {

        case BinaryOp::AND:
            res = lhs_val && rhs_val;
            break;
        case BinaryOp::OR:
            res = lhs_val || rhs_val;
            break;
        case BinaryOp::LESS:
            res = lhs_val < rhs_val;
            break;
        case BinaryOp::GREATER:
            res = lhs_val > rhs_val;
            break;
        case BinaryOp::EQUAL:
            res = lhs_val == rhs_val;
            break;
        case BinaryOp::PLUS:
            res = lhs_val + rhs_val;
            break;
        case BinaryOp::MINUS:
            res = lhs_val - rhs_val;
            break;
        case BinaryOp::STAR:
            res = lhs_val * rhs_val;
            break;
        case BinaryOp::SLASH:
            res = lhs_val / rhs_val;
            break;
        case BinaryOp::MOD:
            res = lhs_val % rhs_val;
            break;
        default:
            throw UnknownOperator();
            break;
    }
    setTos(res);
}

void Interpreter::Visit(std::shared_ptr<True> true_expr) {
    setTos(true);
}

void Interpreter::Visit(std::shared_ptr<False> false_expr) {
    setTos(false);
}

void Interpreter::Visit(std::shared_ptr<Int> int_expr) {
    setTos(int_expr->val);
}

void Interpreter::Visit(std::shared_ptr<New> new_expr) {

}

void Interpreter::Visit(std::shared_ptr<Not> not_expr) {
    not_expr->expression->Accept(shared_from_this());
    setTos(!tos_value_);
}

void Interpreter::Visit(std::shared_ptr<Id> ident_expr) {
    setTos(variables[ident_expr->keyword].value);
}

void Interpreter::Visit(std::shared_ptr<Var> var_decl) {
    reset();
    variables[var_decl->name] = {var_decl->type, false, 0};
}

void Interpreter::Visit(std::shared_ptr<Lvalue> lvalue) {
    // pass
}

int Interpreter::GetResult(std::shared_ptr<Program> program) {
    reset();
    Visit(std::move(program));
    return tos_value_;
}

Interpreter::Interpreter() {
    tos_value_ = 0;
    is_tos_expression_ = false;
}

void Interpreter::setTos(int value) {
    tos_value_ = value;
}

void Interpreter::reset() {
    tos_value_ = 0;
}
