//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_STATEMENT_H
#define COMPILERS_STATEMENT_H

#include "utils/BaseItem.h"

class Statement: virtual public BaseItem {
public:
    virtual void Perform() const = 0;
};
#endif //COMPILERS_STATEMENT_H
