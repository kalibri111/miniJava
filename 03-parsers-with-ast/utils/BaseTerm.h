//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_BASETERM_H
#define COMPILERS_BASETERM_H

#include <memory>
#include "visitor/Visitor.h"

class BaseTerm {
public:
    virtual void Accept(std::shared_ptr<Visitor> visitor) = 0;

    virtual ~BaseTerm() = default;
};
#endif //COMPILERS_BASETERM_H
