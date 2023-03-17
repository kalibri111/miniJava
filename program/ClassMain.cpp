//
// Created by Иван Лескин on 05/03/2023.
//

#include "ClassMain.h"

ClassMain::ClassMain(const std::shared_ptr<StatementsList> &stmtList) : statements_list(stmtList) {}

void ClassMain::Accept(std::shared_ptr<Visitor> visitor) {
    visitor->Visit(shared_from_this());
}
