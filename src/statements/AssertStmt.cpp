#include "statements/AssertStmt.h"


struct AssertException {};

AssertStmt::AssertStmt(std::shared_ptr<ExpressionBase> expr)
  : expression{expr} {
}

void AssertStmt::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}

void AssertStmt::Perform() const {
  if (!expression->Eval()) {
    throw AssertException();
  }
}
