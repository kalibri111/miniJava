//
// Created by Иван Лескин on 05/03/2023.
//

#include "Class.h"

void Class::Accept(std::shared_ptr<Visitor> visitor) {

}

Class::Class(const std::shared_ptr<List> &declList) : decl_list(declList) {}
