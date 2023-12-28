#pragma once
#include "../inc/expression.h"

template <typename V>
class ValueExpression : public Expression {
public:
  virtual ~ValueExpression() = default;
  virtual std::string format() const = 0;
  virtual V getValue() const = 0;
};