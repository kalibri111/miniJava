//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_BASELIST_H
#define COMPILERS_BASELIST_H

#include <memory>
#include <vector>
#include "visitor/Visitor.h"
#include "BaseItem.h"

class BaseList: public std::enable_shared_from_this<BaseList> {
public:
    virtual ~BaseList() = default;

    void AddItem(std::shared_ptr<BaseItem> item);
    void Accept(std::shared_ptr<Visitor> visitor);

    std::vector<std::shared_ptr<BaseItem>> items;
};
#endif //COMPILERS_BASELIST_H
