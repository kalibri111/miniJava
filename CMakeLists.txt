project(MiniJava)
cmake_minimum_required(VERSION 3.0)

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    execute_process(
            COMMAND brew --prefix bison
            RESULT_VARIABLE BREW_BISON
            OUTPUT_VARIABLE BREW_BISON_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_BISON EQUAL 0 AND EXISTS "${BREW_BISON_PREFIX}")
        message(STATUS "Found Bison keg installed by Homebrew at ${BREW_BISON_PREFIX}")
        set(BISON_EXECUTABLE "${BREW_BISON_PREFIX}/bin/bison")
    endif ()

    execute_process(
            COMMAND brew --prefix flex
            RESULT_VARIABLE BREW_FLEX
            OUTPUT_VARIABLE BREW_FLEX_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_FLEX EQUAL 0 AND EXISTS "${BREW_FLEX_PREFIX}")
        message(STATUS "Found Flex keg installed by Homebrew at ${BREW_FLEX_PREFIX}")
        set(FLEX_EXECUTABLE "${BREW_FLEX_PREFIX}/bin/flex")
        include_directories(${BREW_FLEX_PREFIX}/include)
    endif ()
endif ()

find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)
find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(MiniJava ${llvm_libs})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MiniJava_SOURCE_DIR}/bin)

set(
        HEADERS
        driver.hh
        parser.hh
)

BISON_TARGET(
        MyParserWithAst
        parser.y
        ${MiniJava_SOURCE_DIR}/parser.cpp
        #    COMPILE_FLAGS --graph
        DEFINES_FILE ${MiniJava_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScannerWithAst
        scanner.l
        ${MiniJava_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScannerWithAst MyParserWithAst)

add_executable(
        ParserExampleWithAst
        main.cpp
        driver.cpp
        ${BISON_MyParserWithAst_OUTPUTS}
        ${FLEX_MyScannerWithAst_OUTPUTS}

        expressions/BinaryOp.cpp
        expressions/BinaryOp.h
        expressions/Expression.h
        utils/BaseTerm.h
        utils/BaseTerm.h
        visitor/Visitor.h
        expressions/BoolConst.cpp
        expressions/BoolConst.h
        expressions/Id.cpp
        expressions/Id.h
        expressions/Int.cpp
        expressions/Int.h
        expressions/New.cpp
        expressions/New.h
        expressions/Not.cpp
        expressions/Not.h
        declaration/Class.cpp
        declaration/Class.h
        declaration/Declaration.cpp
        declaration/Declaration.h
        utils/BaseList.cpp
        utils/BaseList.h
        utils/BaseItem.h
        declaration/List.h
        declaration/Var.cpp
        declaration/Var.h
        program/program.cpp
        program/program.h
        program/ClassMain.cpp
        program/ClassMain.h
        statements/StatementsList.cpp
        statements/StatementsList.h
        program/ClassDeclList.h
        scopes/Var.cpp
        scopes/Var.h
        statements/Statement.h
        statements/VarDecl.cpp
        statements/VarDecl.h
        statements/Conditional.cpp
        statements/Conditional.h
        utils/forward_decl.h utils/forward_decl.h visitor/PrintVisitor.h utils/forward_include.h statements/AssertStmt.cpp statements/AssignmentStmt.hpp value/lvalue.cpp value/lvalue.h statements/AssignmentStmt.cpp statements/PrintStmt.hpp statements/PrintStmt.cpp statements/StmtListStmt.hpp statements/StmtListStmt.cpp visitor/PrintVisitor.cpp visitor/PrintVisitor.cpp visitor/interpreter.cpp visitor/interpreter.h visitor/interpreter.h)

target_include_directories(
        ParserExampleWithAst PRIVATE ${MiniJava_SOURCE_DIR}
)
#
#add_custom_target(
#        VisitorTree
#        COMMAND dot -Tpng ${MiniJava_SOURCE_DIR}/parser.gv -o ${MiniJava_SOURCE_DIR}/parser.png
#
#        DEPENDS ${MiniJava_SOURCE_DIR}/parser.cpp
#)
#
#add_dependencies(ParserExampleWithAst VisitorTree)


