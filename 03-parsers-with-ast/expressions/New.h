//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_NEW_H
#define COMPILERS_NEW_H

#include "Expression.h"

class New: public Expression,
           public std::enable_shared_from_this<True> {
public:
    int Eval() const override;
    void Accept(std::shared_ptr<Visitor> visitor) override;

private:
    std::string type_;
public:
    explicit New(std::string type);
};
#endif //COMPILERS_NEW_H
