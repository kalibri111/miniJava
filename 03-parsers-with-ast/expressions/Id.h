//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_ID_H
#define COMPILERS_ID_H

#include "Expression.h"

class Id: public Expression,
          public std::enable_shared_from_this<True> {
public:
    int Eval() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;
};
#endif //COMPILERS_ID_H
