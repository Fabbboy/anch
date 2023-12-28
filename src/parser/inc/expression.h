#pragma once
#include "statement.h"
#include <string>

class Expression : public Statement {
public:
  virtual ~Expression() = default;
  virtual std::string format() const = 0;
};