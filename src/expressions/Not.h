//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_NOT_H
#define COMPILERS_NOT_H

#include "ExpressionBase.h"

class Not: public ExpressionBase,
           public std::enable_shared_from_this<Not> {
public:
    int Eval() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;
    std::shared_ptr<ExpressionBase> expression;
public:
    explicit Not(const std::shared_ptr<ExpressionBase> &expression);
};
#endif //COMPILERS_NOT_H
