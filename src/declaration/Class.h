//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_CLASS_H
#define COMPILERS_CLASS_H

#include "Declaration.h"
#include "List.h"

class Class: public Declaration,
             public std::enable_shared_from_this<Class> {
public:
    explicit Class(const std::shared_ptr<List> &declList);

    void Accept(std::shared_ptr<Visitor> visitor) override;

    std::shared_ptr<List> decl_list;
};
#endif //COMPILERS_CLASS_H
