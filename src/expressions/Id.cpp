//
// Created by Иван Лескин on 05/03/2023.
//

#include "Id.h"

int Id::Eval() const {
    return 0;
}

void Id::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}

Id::Id(const std::string &keyword) : keyword(keyword) {}
