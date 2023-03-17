//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_EXPRESSION_H
#define COMPILERS_EXPRESSION_H
#include "utils/BaseTerm.h"

class Expression: virtual public BaseTerm {
public:
    virtual int Eval() const = 0;
};
#endif //COMPILERS_EXPRESSION_H
