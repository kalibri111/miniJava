//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_LIST_H
#define COMPILERS_LIST_H

#include "utils/BaseList.h"

class List: public BaseList, public std::enable_shared_from_this<List> {};
#endif //COMPILERS_LIST_H
