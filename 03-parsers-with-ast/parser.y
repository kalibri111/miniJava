%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    class Scanner;
    class Driver;
    class Expression;
    class NumberExpression;
    class AddExpression;
    class SubstractExpression;
    class DivExpression;
    class IdentExpression;
    class Assignment;
    class StatementList;
    class PowerExpression;
    class Program;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"

    #include "expressions/NumberExpression.h"
    #include "expressions/AddExpression.h"
    #include "expressions/MulExpression.h"
    #include "expressions/DivExpression.h"
    #include "expressions/SubstractExpression.h"
    #include "expressions/IdentExpression.h"
    #include "expressions/PowerExpression.h"
    #include "assignments/Assignment.h"
    #include "assignments/AssignmentList.h"
    #include "Program.h"

    static yy::parser::symbol_type yylex(Scanner &scanner, Driver& driver) {
        return scanner.ScanToken();
    }
}

%lex-param { Scanner &scanner }
%lex-param { Driver &driver }
%parse-param { Scanner &scanner }
%parse-param { Driver &driver }

%locations

%define api.token.prefix {TOK_}

%token
    END 0 "end of file"
    ASSIGN "="
    MINUS "-"
    PLUS "+"
    STAR "*"
    SLASH "/"

    LPAREN "("
    RPAREN ")"
    LBRACET "{"
    RBRACET "}"
    LSQBRACET "["
    RSQBRACET "]"

    POW "**"
    DOT "."
    BR ";"
    AND "&&"
    OR "||"
    LESS "<"
    GREATER ">"
    EQ "=="
    MOD "%"
    CLASS "class"
    WORDINT "int"
    BOOLEAN "boolean"
    TRUE "true"
    FALSE "false"
    VOID "void"
    RET "return"
    MAIN "main"
    NEW "new"
    THIS "this"
    PRINT "System.out.println"
    ASSERT "assert"
    EXTENDS "extends"
;

%token <std::string> IDENTIFIER "identifier"
%token <int> NUMBER "number"
%nterm <int> integer_literal
%nterm <int> binary_operator
%nterm <std::shared_ptr<Lvalue>> lvalue
%nterm <Type> type
%nterm <std::string> simple_type
%nterm <std::string> array_type

%nterm <std::shared_ptr<Program>> program
%nterm <std::shared_ptr<ClassDeclList>> classDeclList
%nterm <std::shared_ptr<ClassMain>> mainClass
%nterm <std::shared_ptr<Class>> classDecl
%nterm <std::shared_ptr<StatementsList>> statementList
%nterm <std::shared_ptr<List>> declList
%nterm <std::shared_ptr<Declaration>> decl
%nterm <std::shared_ptr<Var>> varDecl
%nterm <std::shared_ptr<Statement>> statement
%nterm <std::shared_ptr<Expression>> expr

// %printer { yyo << $$; } <*>;

%%
%start unit;

unit: program
;

program: mainClass { $$ = std::make_shared<Program>($1); driver.program = $$; }} |
         mainClass classDeclList  $$ = std::make_shared<Program>($1, $2); driver.program = $$; }
;

classDeclList: classDecl { $$ = std::make_shared<ClassDeclList>(); $$->AddItem($1); } |
               classDeclList classDecl { $$ = $1; $$->AddItem($2); }
;

mainClass: CLASS ID "{" PUBLIC STATIC VOID MAIN "(" ")" LBRACET "{" statementList "}" "}" { $$ = std::make_shared<ClassMain>($11); }
;

classDecl: CLASS ID "{" declList "}" { $$ = std::make_shared<Class>($4); } |
           CLASS ID EXTENDS ID "{" declList "}" { $$ = std::make_shared<Class>($6); }
;

statementList: statement { $$ = std::make_shared<StatementsList>(); $$->AddItem($1); } |
               statementList statement { $$ = $1; $$->AddItem($2); }
;

statement: verDecl { $$ = std::make_shared<VarDecl>($1); }|
           "{" statementList "}" { $$ = std::make_shared<StatementsList>($2); } |
           IF "(" expr ")" statement { $$ = std::make_shared<IfStmt>($3, $5); } |
           IF "(" expr ")" statement ELSE statement { $$ = std::make_shared<IfElseStmt>($3, $5, $7); } |
           WHILE "(" expr ")" statement { $$ = std::make_shared<WhileStmt>($3, $5); } |
           "System.out.println(" expr ");" { $$ = std::make_shared<PrintStmt>($7); } |
           lvalue "=" expr ";" { $$ = std::make_shared<AssignmentStmt>($1, $3); } |
           RETURN expr ";" |
           methodCall ";"
;

methodCall: expr "." ID "(" rvalArgs ")"
;

rvalArgs: expr |
          expr "," rvalArgs
;

declList: decl | decl declList
;

decl: varDecl | methodDecl
;

varDecl: type ID ";"
;

methodDecl: PUBLIC type ID argList "{" statementList "}"
;

argList: "(" ")" | "(" args ")"
;

args: arg | arg "," args
;

arg: type ID
;

type: primitiveType | arrayType
;

primitiveType: INT | BOOLEAN | VOID | typeId
;

typeId: ID
;

arrayType: primitiveType "[" "]"
;


%left AND OR;
%left EQ NOT;
%left LESS GREATER;
%left PLUS MINUS;
%left STAR SLASH;

expr: expr AND expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::AND     , $3);} |
      expr OR expr  {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::OR     , $3);} |
      expr GREATER expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::GREATER     , $3);} |
      expr EQ expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::EQ     , $3);} |
      expr PLUS expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::PLUS     , $3);} |
      expr MINUS expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::MINUS     , $3);} |
      expr STAR expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::STAR     , $3);} |
      expr SLASH expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::SLASH     , $3);} |
      expr MOD expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::MOD     , $3);} |
      expr "[" expr "]" { $$ = std::make_shared<TrueExpr>(); } |
      new typeId "(" ")" { $$ = std::make_shared<TrueExpr>(); } |
      "(" expr ")" |
      ID { $$ = std::make_shared<Id>($1); } |
      intExpr { $$ = std::make_shared<Int>($1); }|
      THIS |
      TRUE { $$ = std::make_shared<True>($1); }|
      FALSE { $$ = std::make_shared<False>($1); }|
      methodCall |
      NOT expr { $$ = std::make_shared<Not>($1); }
;

intExpr: NUM |
         MINUS NUM
;

binaryOp: OR | AND | LESS | GREATER | PLUS | MINUS | STAR | SLASH | MOD | EQ
;

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
