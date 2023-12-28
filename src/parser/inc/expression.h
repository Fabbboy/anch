#pragma once
#include <string>

class Expression {
public:
  virtual ~Expression() = default;
  virtual std::string format() const = 0;
};