#include "inc/parser.h"
#include "inc/expression.h"
#include "inc/statement.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

// VALUES
#include "expressions/values/float_value.h"
#include "expressions/values/int_value.h"
// OPERATORS
#include "expressions/operators/add_expr.h"
#include "expressions/operators/div_expr.h"
#include "expressions/operators/mod_expr.h"
#include "expressions/operators/mul_expr.h"
#include "expressions/operators/sub_expr.h"

Module Parser::parse() {
  Module module;
  while (index < tokens_size) {
    // TODO: change
    std::unique_ptr<Expression> expr = parse_expression();
    std::cout << expr->format() << std::endl;
    delete expr.release();
  }

  this->tokens_size = 0;
  this->tokens.clear();
  this->index = 0;
  return module;
}

std::unique_ptr<Expression> Parser::parse_expression() {
  std::unique_ptr<Expression> expr = next_expression();

  // Integrate precedence handling here
  expr = parse_with_precedence(std::move(expr), 0);

  return expr;
}

std::unique_ptr<Expression> Parser::parse_with_precedence(std::unique_ptr<Expression> left, int min_precedence) {
  while (peek({Token_t::TOKEN_OPERATOR})) {
    Token *token = next({Token_t::TOKEN_OPERATOR});
    int precedence = get_precedence(token->value[0]);

    if (precedence >= min_precedence) {
      std::unique_ptr<Expression> right = next_expression();
      right = parse_with_precedence(std::move(right), precedence + 1);
      
      switch (token->value[0]) {
        case '+': left = std::make_unique<AddExpression>(std::move(left), std::move(right)); break;
        case '-': left = std::make_unique<SubExpression>(std::move(left), std::move(right)); break;
        case '*': left = std::make_unique<MulExpression>(std::move(left), std::move(right)); break;
        case '/': left = std::make_unique<DivExpression>(std::move(left), std::move(right)); break;
        case '%': left = std::make_unique<ModExpression>(std::move(left), std::move(right)); break;
        default:
          std::string msg = "Unexpected operator: ";
          msg += token->value;
          throw std::runtime_error(msg);
      }
    } else {
      index--; // Put back the token if it's not of higher precedence
      break;
    }
  }
  return left;
}

int Parser::get_precedence(char op) {
  switch (op) {
    case '+': case '-': return 1;
    case '*': case '/' : case '%': return 2;
    default: return -1;
  }
}

std::unique_ptr<Expression> Parser::next_expression() {
  Token *token = next({NUMBER_TOKENS});

  switch (token->type) {
  case TOKEN_INTEGER:
    try {
      return std::make_unique<IntValue>(std::stoi(token->value));
    } catch (std::out_of_range) {
      throw std::runtime_error("Integer out of range");
    }
  case TOKEN_FLOAT:
    try {
      return std::make_unique<FloatValue>(std::stof(token->value));
    } catch (std::out_of_range) {
      throw std::runtime_error("Float out of range");
    }
  case TOKEN_HEX:
    return std::make_unique<IntValue>(std::stoi(token->value, nullptr, 16));
  default:
    throw std::runtime_error("Unexpected token");
  }

  throw std::runtime_error("Unexpected token");
}

Token *Parser::next(std::vector<Token_t> expected,
                    std::vector<std::string> expected_values) {
  if (index >= tokens_size) {
    throw std::runtime_error("Unexpected end of file");
  }

  Token *token = tokens[index];
  if (std::find(expected.begin(), expected.end(), token->type) ==
      expected.end()) {
    throw std::runtime_error("Unexpected token");
  }

  if (!expected_values.empty() &&
      std::find(expected_values.begin(), expected_values.end(), token->value) ==
          expected_values.end()) {
    throw std::runtime_error("Unexpected token value");
  }

  index++;
  return token;
}

bool Parser::peek(std::vector<Token_t> expected,
                  std::vector<std::string> expected_values) {
  if (index >= tokens_size) {
    return false;
  }

  Token *token = tokens[index];
  if (std::find(expected.begin(), expected.end(), token->type) ==
      expected.end()) {
    return false;
  }

  if (!expected_values.empty() &&
      std::find(expected_values.begin(), expected_values.end(), token->value) ==
          expected_values.end()) {
    return false;
  }

  return true;
}