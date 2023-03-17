//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_NOT_H
#define COMPILERS_NOT_H

#include "Expression.h"

class Not: public Expression,
           public std::enable_shared_from_this<Not> {
public:
    int Eval() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;
    std::shared_ptr<Expression> expression;
public:
    explicit Not(const std::shared_ptr<Expression> &expression);
};
#endif //COMPILERS_NOT_H
