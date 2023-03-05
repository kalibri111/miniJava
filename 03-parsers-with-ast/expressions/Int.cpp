//
// Created by Иван Лескин on 05/03/2023.
//

#include "Int.h"

int Int::Eval() const {
    return val;
}

void Int::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(this->shared_from_this());
}

Int::Int(int val) : val(val) {}
