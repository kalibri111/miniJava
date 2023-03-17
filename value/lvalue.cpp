//
// Created by Иван Лескин on 15/03/2023.
//

#include "lvalue.h"
Lvalue::Lvalue(const std::string& name, bool is_array)
        : name{name}, is_array{is_array} {
}

void Lvalue::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}