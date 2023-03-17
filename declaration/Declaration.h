//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_DECLARATION_H
#define COMPILERS_DECLARATION_H

#include "utils/BaseTerm.h"
#include "utils/BaseItem.h"

class Declaration: virtual public BaseItem {
public:
    Type type;
    std::string name;
};
#endif //COMPILERS_DECLARATION_H
