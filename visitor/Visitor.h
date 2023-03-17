//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_VISITOR_H
#define COMPILERS_VISITOR_H
#include <memory>
#include "utils/forward_decl.h"

class Visitor {
public:
    virtual void Visit(std::shared_ptr<True> bc) = 0;
    virtual void Visit(std::shared_ptr<False> bc) = 0;
    virtual void Visit(std::shared_ptr<Var> v) = 0;
    virtual void Visit(std::shared_ptr<Id> v) = 0;
    virtual void Visit(std::shared_ptr<Int> v) = 0;
    virtual void Visit(std::shared_ptr<New> v) = 0;
    virtual void Visit(std::shared_ptr<Not> v) = 0;
    virtual void Visit(std::shared_ptr<ClassMain> v) = 0;
    virtual void Visit(std::shared_ptr<Program> v) = 0;
    virtual void Visit(std::shared_ptr<LocalVarDeclStmt>) = 0;
    virtual void Visit(std::shared_ptr<Lvalue>) = 0;
    virtual void Visit(std::shared_ptr<AssertStmt>) = 0;
    virtual void Visit(std::shared_ptr<AssignmentStmt>) = 0;
    virtual void Visit(std::shared_ptr<StmtListStmt>) = 0;
    virtual void Visit(std::shared_ptr<BinaryOp>) = 0;
    virtual void Visit(std::shared_ptr<PrintStmt>) = 0;
    virtual void Visit(std::shared_ptr<While>) = 0;
    virtual void Visit(std::shared_ptr<IfElse>) = 0;
    virtual void Visit(std::shared_ptr<If>) = 0;



};
#endif //COMPILERS_VISITOR_H
