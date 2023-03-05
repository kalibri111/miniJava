//
// Created by Иван Лескин on 05/03/2023.
//

#include "BinaryOp.h"

int BinaryOp::Eval() const {
    switch (op) {

        case AND:
            return lhs->Eval() && rhs->Eval();
            break;
        case OR:
            return lhs->Eval() || rhs->Eval();
            break;
        case LESS:
            return lhs->Eval() < rhs->Eval();
            break;
        case GREATER:
            return lhs->Eval() > rhs->Eval();
            break;
        case EQUAL:
            return lhs->Eval() == rhs->Eval();
            break;
        case PLUS:
            return lhs->Eval() + rhs->Eval();
            break;
        case MINUS:
            return lhs->Eval() - rhs->Eval();
            break;
        case STAR:
            return lhs->Eval() * rhs->Eval();
            break;
        case SLASH:
            return lhs->Eval() / rhs->Eval();
            break;
        case MOD:
            return lhs->Eval() % rhs->Eval();
            break;
    }
}