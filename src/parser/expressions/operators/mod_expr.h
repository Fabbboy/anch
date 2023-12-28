#pragma once

#include "../binary_expr.h"

class ModExpression : public BinaryExpression {
public:
  ModExpression(std::unique_ptr<Expression> left,
                std::unique_ptr<Expression> right)
      : BinaryExpression(std::move(left), std::move(right)) {}
  virtual ~ModExpression() = default;

  virtual std::string format() const override {
    std::string left = this->left->format();
    std::string right = this->right->format();
    std::string result = "ModExpression(";
    result += left;
    result += ", ";
    result += right;
    result += ")";
    return result;
  }
};