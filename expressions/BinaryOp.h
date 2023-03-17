//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_BINARYOP_H
#define COMPILERS_BINARYOP_H

#include "Expression.h"


class BinaryOp: public Expression, public std::enable_shared_from_this<BinaryOp>{
public:
    enum Operation {
        AND,
        OR,
        LESS,
        GREATER,
        EQUAL,
        PLUS,
        MINUS,
        STAR,
        SLASH,
        MOD,
    };

    void Accept(std::shared_ptr<Visitor> visitor) override;

    BinaryOp(const std::shared_ptr<Expression> &lhs, Operation op, const std::shared_ptr<Expression> &rhs);

    int Eval() const override;

    std::shared_ptr<Expression> lhs;
    std::shared_ptr<Expression> rhs;
    Operation op;
};
#endif //COMPILERS_BINARYOP_H
