//
// Created by Иван Лескин on 05/03/2023.
//

#include "BoolConst.h"

int True::Eval() const {
    return true;
}

void True::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(this->shared_from_this());
}

int False::Eval() const {
    return false;
}

void False::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}
