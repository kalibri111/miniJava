//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_BOOLCONST_H
#define COMPILERS_BOOLCONST_H

#include "Expression.h"

class True: public Expression,
                public std::enable_shared_from_this<True> {
public:
    int Eval() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;
};

class False: public Expression,
                 public std::enable_shared_from_this<False> {
public:
    int Eval() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;
};
#endif //COMPILERS_BOOLCONST_H
