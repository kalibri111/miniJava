#include "statements/PrintStmt.hpp"


PrintStmt::PrintStmt(std::shared_ptr<Expression> expr) : expression{expr} {
}

void PrintStmt::Perform() const {
  std::cout << "Print: " << expression->Eval();
}

void PrintStmt::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}
