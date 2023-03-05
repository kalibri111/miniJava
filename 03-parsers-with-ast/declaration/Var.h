//
// Created by Иван Лескин on 05/03/2023.
//

#ifndef COMPILERS_VAR_H
#define COMPILERS_VAR_H

#include "Declaration.h"

class Var: virtual public Declaration, public std::enable_shared_from_this<Var> {
    void Accept(std::shared_ptr<Visitor> visitor) override;
    std::string name;
public:
    explicit Var(const std::string &name);
};
#endif //COMPILERS_VAR_H
