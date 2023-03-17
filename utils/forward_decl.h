//
// Created by Иван Лескин on 15/03/2023.
//

#ifndef MINIJAVA_FORWARD_DECL_H
#define MINIJAVA_FORWARD_DECL_H

// declaration
class Class;
class Declaration;
class List;
class Var;
// expression
class BinaryOp;
class True;
class False;
class Expression;
class Id;
class Int;
class New;
class Not;
// program
class ClassDeclList;
class ClassMain;
class Program;
// statements
class Var;
class If;
class IfElse;
class While;
class Statement;
class StatementsList;
class LocalVarDeclStmt;
class AssertStmt;
class AssignmentStmt;
class PrintStmt;
class StmtListStmt;
// value
class Lvalue;
// type
struct Type {
    std::string type;
    bool is_array;
} ;
#endif //MINIJAVA_FORWARD_DECL_H
