//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_CLASSMAIN_H
#define COMPILERS_CLASSMAIN_H

#include <memory>
#include "visitor/Visitor.h"
#include "statements/StatementsList.h"

class ClassMain: public std::enable_shared_from_this<ClassMain> {
public:
    explicit ClassMain(const std::shared_ptr<StatementsList> &stmtList);

    void Accept(std::shared_ptr<Visitor> visitor);

    std::shared_ptr<StatementsList> statements_list;
};
#endif //COMPILERS_CLASSMAIN_H
