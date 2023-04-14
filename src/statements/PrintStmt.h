#pragma once

#include <iostream>
#include "Statement.h"
#include "expressions/ExpressionBase.h"


class PrintStmt: public Statement,
  public std::enable_shared_from_this<PrintStmt> {
 public:
  PrintStmt(std::shared_ptr<ExpressionBase> expr);

  void Perform() const override;
  void Accept(std::shared_ptr<Visitor> visitor) override;

  std::shared_ptr<ExpressionBase> expression;

};
