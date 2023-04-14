#include "statements/AssignmentStmt.h"


AssignmentStmt::AssignmentStmt(std::shared_ptr<Lvalue> lvalue,
    std::shared_ptr<ExpressionBase> expr)
  : lvalue{lvalue}, expr{expr} {
}

void AssignmentStmt::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}

void AssignmentStmt::Perform() const {
}
