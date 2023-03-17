#pragma once


#include <memory>
#include "Statement.h"
#include "expressions/Expression.h"

class AssertStmt: public Statement,
                  public std::enable_shared_from_this<AssertStmt> {
 public:
  AssertStmt(std::shared_ptr<Expression> expr);
  void Accept(std::shared_ptr<Visitor> visitor) override;
  void Perform() const override;

  std::shared_ptr<Expression> expression;
};
