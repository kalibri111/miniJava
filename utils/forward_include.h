//
// Created by Иван Лескин on 15/03/2023.
//

#ifndef MINIJAVA_FORWARD_INCLUDE_H
#define MINIJAVA_FORWARD_INCLUDE_H
// declaration
#include "declaration/Class.h"
#include "declaration/Declaration.h"
#include "declaration/List.h"
#include "declaration/Var.h"
// expressions
#include "expressions/BinaryOp.h"
#include "expressions/BoolConst.h"
#include "expressions/Id.h"
#include "expressions/Int.h"
#include "expressions/New.h"
#include "expressions/Not.h"
// program
#include "program/ClassDeclList.h"
#include "program/ClassMain.h"
#include "program/program.h"
// scopes
#include "scopes/Var.h"
// statements
#include "statements/Conditional.h"
#include "statements/Statement.h"
#include "statements/StatementsList.h"
#include "statements/VarDecl.h"
#include "statements/AssertStmt.hpp"
#include "statements/AssignmentStmt.hpp"
#include "statements/PrintStmt.hpp"
#include "statements/StmtListStmt.hpp"
// value
#include "value/lvalue.h"
#endif //MINIJAVA_FORWARD_INCLUDE_H
