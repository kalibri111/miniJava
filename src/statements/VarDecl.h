//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_VARDECL_H
#define COMPILERS_VARDECL_H

#include "Statement.h"

class LocalVarDeclStmt: public Statement,
                        public std::enable_shared_from_this<LocalVarDeclStmt> {
public:
    void Accept(std::shared_ptr<Visitor> visitor) override;

    explicit LocalVarDeclStmt(const std::shared_ptr<Var> &varDecl);

    void Perform() const override;

    std::shared_ptr<Var> var_decl;
};
#endif //COMPILERS_VARDECL_H
