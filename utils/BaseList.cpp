//
// Created by Иван Лескин on 05/03/2023.
//

#include "BaseList.h"

void BaseList::AddItem(std::shared_ptr<BaseItem> item) {
    items.push_back(item);
}

void BaseList::Accept(std::shared_ptr<Visitor> visitor) {
    for (const auto& i: items) {
        i->Accept(visitor);
    }
}
