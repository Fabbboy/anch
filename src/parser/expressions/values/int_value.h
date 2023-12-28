#include "../value_expression.h"

class IntValue : public ValueExpression<int> {
public:
  IntValue(int value) : value(value) {}
  ~IntValue() = default;

  std::string format() const override { return "IntValue(" + std::to_string(value) + ")"; }
  int getValue() const override { return value; }

private:
  int value;
};
