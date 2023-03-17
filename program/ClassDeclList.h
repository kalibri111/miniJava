//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_CLASSDECLLIST_H
#define COMPILERS_CLASSDECLLIST_H

#include "utils/BaseList.h"

class ClassDeclList: public BaseList, public std::enable_shared_from_this<ClassDeclList> {};
#endif //COMPILERS_CLASSDECLLIST_H
