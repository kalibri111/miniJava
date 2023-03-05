//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_INT_H
#define COMPILERS_INT_H

#include "Expression.h"

class Int: public Expression,
           public std::enable_shared_from_this<True> {
public:
    int Eval() const override;

    explicit Int(int val);

    void Accept(std::shared_ptr<Visitor> visitor) override;

    int val;
};
#endif //COMPILERS_INT_H
