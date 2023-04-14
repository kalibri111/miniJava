//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_INT_H
#define COMPILERS_INT_H

#include "ExpressionBase.h"

class Int: public ExpressionBase,
           public std::enable_shared_from_this<Int> {
public:
    int Eval() const override;

    explicit Int(int val);

    void Accept(std::shared_ptr<Visitor> visitor) override;

    int val;
};
#endif //COMPILERS_INT_H
