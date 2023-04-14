#include "statements/StmtListStmt.h"


StmtListStmt::StmtListStmt(std::shared_ptr<StatementsList> stmt_list)
  : statement_list{stmt_list} {
}

void StmtListStmt::Accept(std::shared_ptr<Visitor> visitor) {
  visitor->Visit(shared_from_this());
}

void StmtListStmt::Perform() const {
  for (auto item : statement_list->items) {
    std::dynamic_pointer_cast<Statement>(item)->Perform();
  }
}
