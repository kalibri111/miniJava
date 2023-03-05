//
// Created by Иван Лескин on 05/03/2023.
//

#include "VarDecl.h"

LocalVarDeclStmt::LocalVarDeclStmt(const std::shared_ptr<Var> &varDecl) : var_decl(varDecl) {}

void LocalVarDeclStmt::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}

void LocalVarDeclStmt::Perform() const {

}
