//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_PROGRAM_H
#define COMPILERS_PROGRAM_H

#include <memory>
#include "declaration/List.h"
#include "ClassMain.h"
#include "ClassDeclList.h"

class Program: public std::enable_shared_from_this<Program> {
public:
    Program(const std::shared_ptr<ClassMain> &mainClass, const std::shared_ptr<ClassDeclList> &classDeclList);

    explicit Program(const std::shared_ptr<ClassMain> &mainClass);

    void Accept(std::shared_ptr<Visitor> visitor);

    std::shared_ptr<ClassMain> main_class;
    std::shared_ptr<ClassDeclList> class_decl_list;
};
#endif //COMPILERS_PROGRAM_H
