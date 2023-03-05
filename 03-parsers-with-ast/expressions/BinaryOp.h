//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_BINARYOP_H
#define COMPILERS_BINARYOP_H

#include "Expression.h"
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

class BinaryOp: public Expression, public std::enable_shared_from_this<BinaryOp>{
public:
    BinaryOp(std::shared_ptr<Expression> lhs, std::shared_ptr<Expression> rhs);
    void Accept(std::shared_ptr<Visitor> visitor) override;
    int Eval() const;

    std::shared_ptr<Expression> lhs;
    std::shared_ptr<Expression> rhs;
    Operation op;
};
#endif //COMPILERS_BINARYOP_H
