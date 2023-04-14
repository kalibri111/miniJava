//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_ID_H
#define COMPILERS_ID_H

#include "ExpressionBase.h"

class Id: public ExpressionBase,
          public std::enable_shared_from_this<Id> {
public:
    int Eval() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;

    explicit Id(const std::string &keyword);

    std::string keyword;
};
#endif //COMPILERS_ID_H
