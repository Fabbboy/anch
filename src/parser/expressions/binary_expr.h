#pragma once

#include "../inc/expression.h"
#include <memory>

class BinaryExpression : public Expression {
public:
  BinaryExpression(std::unique_ptr<Expression> left,
                   std::unique_ptr<Expression> right)
      : left(std::move(left)), right(std::move(right)) {}
  virtual ~BinaryExpression() = default;

protected:
  std::unique_ptr<Expression> left;
  std::unique_ptr<Expression> right;
};
