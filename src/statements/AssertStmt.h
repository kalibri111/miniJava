#pragma once


#include <memory>
#include "Statement.h"
#include "expressions/ExpressionBase.h"

class AssertStmt: public Statement,
                  public std::enable_shared_from_this<AssertStmt> {
 public:
  AssertStmt(std::shared_ptr<ExpressionBase> expr);
  void Accept(std::shared_ptr<Visitor> visitor) override;
  void Perform() const override;

  std::shared_ptr<ExpressionBase> expression;
};
