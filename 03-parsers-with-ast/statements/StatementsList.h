//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_STATEMENTSLIST_H
#define COMPILERS_STATEMENTSLIST_H

#include "utils/BaseList.h"

class StatementsList: public BaseList, public std::enable_shared_from_this<StatementsList>{};
#endif //COMPILERS_STATEMENTSLIST_H
