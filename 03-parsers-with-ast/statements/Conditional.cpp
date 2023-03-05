//
// Created by Иван Лескин on 05/03/2023.
//

#include "Conditional.h"
If::If(std::shared_ptr<Expression> expr,
               std::shared_ptr<Statement> stmt) : expr{expr}, stmt{stmt} {
}

void If::Perform() const {
    if (expr->Eval()) { stmt->Perform(); }
}

void If::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}


IfElse::IfElse(std::shared_ptr<Expression> expr,
                       std::shared_ptr<Statement> stmt_true,
                       std::shared_ptr<Statement> stmt_false)
        : expr{expr}, stmt_true{stmt_true}, stmt_false{stmt_false} {
}

void IfElse::Perform() const {
    if (expr->Eval()) { stmt_true->Perform(); } else { stmt_false->Perform(); }
}

void IfElse::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}


While::While(std::shared_ptr<Expression> expr,
                     std::shared_ptr<Statement> stmt) : expr{expr}, stmt{stmt} {
}

void While::Perform() const {
    while (expr->Eval()) { stmt->Perform(); }
}

void While::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}