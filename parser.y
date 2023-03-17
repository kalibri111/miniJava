%skeleton "lalr1.cc"
%require "3.5"

%defines
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <string>
    #include <functional>
    #include <memory>
    #include <string>
    #include "utils/forward_decl.h"

    class Scanner;
    class Driver;
}

// %param { Driver &drv }

%define parse.trace
%define parse.error verbose

%code {
    #include "driver.hh"
    #include "location.hh"
    #include "utils/forward_include.h"

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
    <int> MINUS "-"
    <int> PLUS "+"
    <int> STAR "*"
    <int> SLASH "/"
    <int> AND "&&"
    <int> OR "||"
    <int> LESS "<"
    <int> GREATER ">"
    <int> EQUAL "=="
    <int> MOD "%"

%token
    LPAREN "("
    RPAREN ")"
    LBRACET "{"
    RBRACET "}"
    LSQBRACET "["
    RSQBRACET "]"
    DOT "."
    COLON ","
    SEMICOLON ";"

%token
    NEW "new"
    THIS "this"
    TRUE "true"
    FALSE "false"
    IF "if"
    ELSE "else"
    WHILE "while"
    ASSERT "assert"
    CLASS "class"
    EXTENDS "extends"
    PUBLIC "public"
    STATIC "static"
    RET "return"

%token
    INT "int"
    BOOLEAN "boolean"
    VOID "void"

%token
    MAIN "main"
    PRINT "System.out.println"
    LENGTH "length"
;

%token <int> NUMBER "number"
%token <std::string> ID "identifier"
%nterm <int> intExpr
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
%start program;

program: mainClass { $$ = std::make_shared<Program>($1); driver.program = $$; } |
         mainClass classDeclList  { $$ = std::make_shared<Program>($1, $2); driver.program = $$; }
;

classDeclList: classDecl { $$ = std::make_shared<ClassDeclList>(); $$->AddItem($1); } |
               classDeclList classDecl { $$ = $1; $$->AddItem($2); }
;

mainClass: CLASS ID "{" PUBLIC STATIC VOID MAIN "(" ")" "{" statementList "}" "}" { $$ = std::make_shared<ClassMain>($11); }
;

classDecl: CLASS ID "{" declList "}" { $$ = std::make_shared<Class>($4); } |
           CLASS ID EXTENDS ID "{" declList "}" { $$ = std::make_shared<Class>($6); }
;

statementList: statement { $$ = std::make_shared<StatementsList>(); $$->AddItem($1); } |
               statementList statement { $$ = $1; $$->AddItem($2); }
;

statement: varDecl { $$ = std::make_shared<LocalVarDeclStmt>($1); }|
           "{" statementList "}" { $$ = std::make_shared<StmtListStmt>($2); } |
           IF "(" expr ")" statement { $$ = std::make_shared<If>($3, $5); } |
           IF "(" expr ")" statement ELSE statement { $$ = std::make_shared<IfElse>($3, $5, $7); } |
           WHILE "(" expr ")" statement { $$ = std::make_shared<While>($3, $5); } |
           "System.out.println(" expr ");" { $$ = std::make_shared<PrintStmt>($2); } |
           lvalue "=" expr ";" { $$ = std::make_shared<AssignmentStmt>($1, $3); } |
           RET expr ";" |
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
%left EQUAL NOT;
%left LESS GREATER;
%left PLUS MINUS;
%left STAR SLASH;

expr: expr AND expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::AND     , $3);} |
      expr OR expr  {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::OR     , $3);} |
      expr GREATER expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::GREATER     , $3);} |
      expr EQUAL expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::EQUAL     , $3);} |
      expr PLUS expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::PLUS     , $3);} |
      expr MINUS expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::MINUS     , $3);} |
      expr STAR expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::STAR     , $3);} |
      expr SLASH expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::SLASH     , $3);} |
      expr MOD expr {$$ = std::make_shared<BinaryOp>($1, BinaryOp::Operation::MOD     , $3);} |
      expr "[" expr "]" { $$ = std::make_shared<True>(); } |
      NEW typeId "(" ")" { $$ = std::make_shared<True>(); } |
      "(" expr ")" |
      ID { $$ = std::make_shared<Id>($1); } |
      intExpr { $$ = std::make_shared<Int>($1); }|
      THIS |
      TRUE { $$ = std::make_shared<True>(); }|
      FALSE { $$ = std::make_shared<False>(); }|
      methodCall |
      NOT expr { $$ = std::make_shared<Not>($2); }
;

intExpr: "number" { $$ = $1; }
       | "-" "number" { $$ = -$2; };

binaryOp: OR | AND | LESS | GREATER | PLUS | MINUS | STAR | SLASH | MOD | EQUAL
;

%%

void
yy::parser::error(const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
