//
// Created by Иван Лескин on 05/03/2023.
//

#include "BinaryOp.h"

int BinaryOp::Eval() const {
    switch (op) {
        case AND:
            return lhs->Eval() && rhs->Eval();
        case OR:
            return lhs->Eval() || rhs->Eval();
        case LESS:
            return lhs->Eval() < rhs->Eval();
        case GREATER:
            return lhs->Eval() > rhs->Eval();
        case EQUAL:
            return lhs->Eval() == rhs->Eval();
        case PLUS:
            return lhs->Eval() + rhs->Eval();
        case MINUS:
            return lhs->Eval() - rhs->Eval();
        case STAR:
            return lhs->Eval() * rhs->Eval();
        case SLASH:
            return lhs->Eval() / rhs->Eval();
        case MOD:
            return lhs->Eval() % rhs->Eval();
    }
}

BinaryOp::BinaryOp(const std::shared_ptr<ExpressionBase> &lhs, BinaryOp::Operation op, const std::shared_ptr<ExpressionBase> &rhs) : lhs(lhs), rhs(rhs), op(op) {}

void BinaryOp::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}

