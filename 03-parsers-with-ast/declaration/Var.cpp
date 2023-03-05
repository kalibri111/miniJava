//
// Created by Иван Лескин on 05/03/2023.
//

#include "Var.h"

void Var::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}

Var::Var(const std::string &name) : name(name) {}
