//
// Created by Иван Лескин on 16/03/2023.
//
#include "PrintVisitor.h"

void PrintVisitor::Visit(std::shared_ptr<Program> program) {
    stream_ << "PROGRAM\n";
    num_tabs_ += 1;
    program->main_class->Accept(shared_from_this());
    program->class_decl_list->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<ClassMain> main_class) {
    PrintTabs();
    stream_ << "MAIN CLASS\n";
    num_tabs_ += 1;
    main_class->statements_list->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<AssertStmt> assert_stmt) {
    PrintTabs();
    stream_ << "ASSERT STATEMENT\n";
    num_tabs_ += 1;
    assert_stmt->expression->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<LocalVarDeclStmt> local_var_decl_stmt) {
    PrintTabs();
    stream_ << "LOCAL VARIABLE DECLARATION STATEMENT\n";

    num_tabs_ += 1;
    local_var_decl_stmt->var_decl->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<StmtListStmt> stmt_list_stmt) {
    PrintTabs();
    stream_ << "STATEMENT LIST STATEMENT\n";
    num_tabs_ += 1;
    stmt_list_stmt->statement_list->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<If> if_stmt) {
    PrintTabs();
    stream_ << "IF STATEMENT\n";
    num_tabs_ += 1;
    if_stmt->expression->Accept(shared_from_this());
    if_stmt->statement->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<IfElse> if_else_stmt) {
    PrintTabs();
    stream_ << "IF-ELSE STATEMENT\n";
    num_tabs_ += 1;
    if_else_stmt->expression->Accept(shared_from_this());
    if_else_stmt->stmt_true->Accept(shared_from_this());
    if_else_stmt->stmt_false->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<While> while_stmt) {
    PrintTabs();
    stream_ << "WHILE STATEMENT\n";
    num_tabs_ += 1;
    while_stmt->expression->Accept(shared_from_this());
    while_stmt->statement->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<PrintStmt> print_stmt) {
    PrintTabs();
    stream_ << "PRINT STATEMENT\n";
    num_tabs_ += 1;
    print_stmt->expression->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<AssignmentStmt> assignment_stmt) {
    PrintTabs();
    stream_ << "ASSIGMENT LIST\n";
    num_tabs_ += 1;
    assignment_stmt->lvalue->Accept(shared_from_this());
    assignment_stmt->expr->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<BinaryOp> bin_op_expr) {
    PrintTabs();
    stream_ << "BINARY OPERATION\n";
    num_tabs_ += 1;
    bin_op_expr->lhs->Accept(shared_from_this());
    PrintTabs();
    stream_ << (int) bin_op_expr->op << "\n";
    bin_op_expr->rhs->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<True> true_expr) {
    PrintTabs();
    stream_ << "true EXPRESSION\n";
}

void PrintVisitor::Visit(std::shared_ptr<False> false_expr) {
    PrintTabs();
    stream_ << "false EXPRESSION\n";
}

void PrintVisitor::Visit(std::shared_ptr<Int> int_expr) {
    PrintTabs();
    stream_ << "int EXPRESSION\n";
}

void PrintVisitor::Visit(std::shared_ptr<New> new_expr) {
    PrintTabs();
    stream_ << "new EXPRESSION\n";
}

void PrintVisitor::Visit(std::shared_ptr<Not> not_expr) {
    PrintTabs();
    stream_ << "not EXPRESSION\n";
    num_tabs_ += 1;
    not_expr->expression->Accept(shared_from_this());
    num_tabs_ -= 1;
}

void PrintVisitor::Visit(std::shared_ptr<Id> ident_expr) {
    PrintTabs();
    stream_ << "KEYWORD " << ident_expr->keyword << "\n";
}

void PrintVisitor::Visit(std::shared_ptr<Var> var_decl) {
    PrintTabs();
    stream_ << "VARIABLE " << var_decl->type.type << " "
            << "ARRAY: " << var_decl->type.is_array << " "
            << var_decl->name << "\n";
}

void PrintVisitor::Visit(std::shared_ptr<Lvalue> lvalue) {
    PrintTabs();
    stream_ << "VALUE " << lvalue->name << " "
            << "ARRAY: " << lvalue->is_array << "\n";
}

void PrintVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << "\t";
    }
}

PrintVisitor::PrintVisitor(const std::string &filename) {
    stream_.open(filename);
}

PrintVisitor::~PrintVisitor() {
    stream_.close();
}
