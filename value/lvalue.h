//
// Created by Иван Лескин on 15/03/2023.
//

#ifndef MINIJAVA_LVALUE_H
#define MINIJAVA_LVALUE_H
#include <memory>
#include "visitor/Visitor.h"
#include "utils/BaseItem.h"

class Lvalue: public BaseItem,
              public std::enable_shared_from_this<Lvalue> {
public:
    Lvalue(const std::string& name, bool is_array);
    void Accept(std::shared_ptr<Visitor> visitor) override;

    std::string name;
    bool is_array;
};
#endif //MINIJAVA_LVALUE_H
