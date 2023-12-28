#pragma once

#include "../value_expression.h"

class FloatValue : public ValueExpression<float> {
public:
  FloatValue(float value) : value(value) {}
  ~FloatValue() = default;

  std::string format() const override { return "FloatValue(" + std::to_string(value) + ")"; }
  float getValue() const override { return value; }

private:
  float value;
};