#pragma once

#include <memory>
#include "Statement.h"
#include "StatementsList.h"

class StmtListStmt: public Statement,
                    public std::enable_shared_from_this<StmtListStmt> {
 public:
  StmtListStmt(std::shared_ptr<StatementsList> stmt_list);
  void Accept(std::shared_ptr<Visitor> visitor) override;
  void Perform() const override;

  std::shared_ptr<StatementsList> statement_list;
};
