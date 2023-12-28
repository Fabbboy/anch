#pragma once

#include "../binary_expr.h"

class MulExpression : public BinaryExpression {
public:
  MulExpression(std::unique_ptr<Expression> left,
                std::unique_ptr<Expression> right)
      : BinaryExpression(std::move(left), std::move(right)) {}
  virtual ~MulExpression() = default;

  virtual std::string format() const override {
    std::string left = this->left->format();
    std::string right = this->right->format();
    std::string result = "MulExpression(";
    result += left;
    result += ", ";
    result += right;
    result += ")";
    return result;
  }
};