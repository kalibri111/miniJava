//
// Created by Иван Лескин on 15/03/2023.
//

#ifndef MINIJAVA_PRINTVISITOR_H
#define MINIJAVA_PRINTVISITOR_H
#include "Visitor.h"
#include "fstream"
#include "utils/forward_include.h"

class PrintVisitor: public Visitor,
                    public std::enable_shared_from_this<PrintVisitor> {
public:
    PrintVisitor(const std::string& filename);

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

    ~PrintVisitor();

private:
    void PrintTabs();

private:
    size_t num_tabs_ = 0;
    std::ofstream stream_;
};
#endif //MINIJAVA_PRINTVISITOR_H
