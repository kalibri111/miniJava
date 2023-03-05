//
// Created by Иван Лескин on 05/03/2023.
//

#include "New.h"

#include <utility>

New::New(std::string type) : type_(std::move(type)) {}

int New::Eval() const {
    return 0;
}

void New::Accept(std::shared_ptr<Visitor> visitor) {

}
