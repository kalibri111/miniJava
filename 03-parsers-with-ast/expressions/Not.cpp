//
// Created by Иван Лескин on 05/03/2023.
//

#include "Not.h"

Not::Not(const std::shared_ptr<Expression> &expression) : expression(expression) {}

int Not::Eval() const {
    return ! expression->Eval();
}

void Not::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}
