//
// Created by Иван Лескин on 05/03/2023.
//

#include "program.h"

Program::Program(const std::shared_ptr<ClassMain> &mainClass, const std::shared_ptr<ClassDeclList> &classDeclList)
        : main_class(mainClass), class_decl_list(classDeclList) {}

Program::Program(const std::shared_ptr<ClassMain> &mainClass) : main_class(mainClass) {}

void Program::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}
