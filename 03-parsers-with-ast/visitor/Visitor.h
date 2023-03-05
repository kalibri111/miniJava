//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_VISITOR_H
#define COMPILERS_VISITOR_H
#include <memory>
#include <expressions/BoolConst.h>
#include "declaration/Var.h"
#include "declaration/Class.h"
#include "expressions/Id.h"
#include "expressions/Int.h"
#include "expressions/New.h"
#include "expressions/Not.h"
#include "program/ClassDeclList.h"
#include "program/ClassMain.h"
#include "Program.h"
#include "utils/BaseItem.h"

class Visitor {
public:
    virtual void Visit(std::shared_ptr<True> bc) = 0;
    virtual void Visit(std::shared_ptr<False> bc) = 0;
    virtual void Visit(std::shared_ptr<Var> v) = 0;
    virtual void Visit(std::shared_ptr<Id> v) = 0;
    virtual void Visit(std::shared_ptr<Int> v) = 0;
    virtual void Visit(std::shared_ptr<New> v) = 0;
    virtual void Visit(std::shared_ptr<Not> v) = 0;
    virtual void Visit(std::shared_ptr<ClassDeclList> v) = 0;
    virtual void Visit(std::shared_ptr<ClassMain> v) = 0;
    virtual void Visit(std::shared_ptr<Program> v) = 0;
    virtual void Visit(std::shared_ptr<StatementsList> v) = 0;
    virtual void Visit(std::shared_ptr<List> v) = 0;
};
#endif //COMPILERS_VISITOR_H
