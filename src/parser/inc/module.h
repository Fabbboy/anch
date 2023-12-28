#pragma once

#include "expression.h"
#include "statement.h"
#include <memory>
#include <vector>

class Module {
public:
  Module(){};
  ~Module() = default;

  void add_statement(std::shared_ptr<Statement> statement) {
    this->statements.push_back(std::move(statement));
  }

private:
  std::vector<std::shared_ptr<Statement>> statements;
};
