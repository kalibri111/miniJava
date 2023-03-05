//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_DECLARATION_H
#define COMPILERS_DECLARATION_H

#include "utils/BaseTerm.h"

class Declaration: virtual public BaseTerm {
public:
    std::string name;
};
#endif //COMPILERS_DECLARATION_H
