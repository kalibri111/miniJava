//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_BASEITEM_H
#define COMPILERS_BASEITEM_H

#include <memory>
#include "visitor/Visitor.h"

class BaseItem{
public:
    virtual void Accept(std::shared_ptr<Visitor> visitor) = 0;

    virtual ~BaseItem() = default;
};
#endif //COMPILERS_BASEITEM_H
