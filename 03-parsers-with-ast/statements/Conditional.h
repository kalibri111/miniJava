//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_CONDITIONAL_H
#define COMPILERS_CONDITIONAL_H

#include "Statement.h"

class If: public Statement,
          public std::enable_shared_from_this<If> {
public:
    If(std::shared_ptr<Expression> expr, std::shared_ptr<Statement> stmt);

    void Perform() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;

    std::shared_ptr<Expression> expr;
    std::shared_ptr<Statement> stmt;
};


class IfElse: public Statement,
              public std::enable_shared_from_this<IfElse> {
public:
    IfElse(std::shared_ptr<Expression> expr,
           std::shared_ptr<Statement> stmt_true,
           std::shared_ptr<Statement> stmt_false);

    void Perform() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;

    std::shared_ptr<Expression> expr;
    std::shared_ptr<Statement> stmt_true;
    std::shared_ptr<Statement> stmt_false;
};


class While: public Statement,
             public std::enable_shared_from_this<While> {
public:
    While(std::shared_ptr<Expression> expr, std::shared_ptr<Statement> stmt);

    void Perform() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;

    std::shared_ptr<Expression> expr;
    std::shared_ptr<Statement> stmt;
};
#endif //COMPILERS_CONDITIONAL_H
