project(ParserExampleWithAst)
set(
    HEADERS
    driver.hh
    parser.hh
    )

BISON_TARGET(
    MyParserWithAst
    parser.y
    ${ParserExampleWithAst_SOURCE_DIR}/parser.cpp
    DEFINES_FILE ${ParserExampleWithAst_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
    MyScannerWithAst
    scanner.l
    ${ParserExampleWithAst_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScannerWithAst MyParserWithAst)

add_executable(
    ParserExampleWithAst
    main.cpp
    driver.cpp
    ${BISON_MyParserWithAst_OUTPUTS}
    ${FLEX_MyScannerWithAst_OUTPUTS}

    Program.cpp
        expressions/BinaryOp.cpp expressions/BinaryOp.h expressions/Expression.h utils/BaseTerm.h utils/BaseTerm.h visitor/Visitor.h expressions/BoolConst.cpp expressions/BoolConst.h expressions/Id.cpp expressions/Id.h expressions/Int.cpp expressions/Int.h expressions/New.cpp expressions/New.h expressions/Not.cpp expressions/Not.h declaration/Class.cpp declaration/Class.h declaration/Declaration.cpp declaration/Declaration.h utils/BaseList.cpp utils/BaseList.h utils/BaseItem.h declaration/List.h declaration/Var.cpp declaration/Var.h program/program.cpp program/program.h program/ClassMain.cpp program/ClassMain.h statements/StatementsList.cpp statements/StatementsList.h program/ClassDeclList.h scopes/Var.cpp scopes/Var.h statements/Statement.h statements/VarDecl.cpp statements/VarDecl.h statements/Conditional.cpp statements/Conditional.h)

target_include_directories(
    ParserExampleWithAst PRIVATE ${ParserExampleWithAst_SOURCE_DIR}
)



