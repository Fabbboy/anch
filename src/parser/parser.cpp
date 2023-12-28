#include "inc/parser.h"
#include "inc/expression.h"
#include "inc/statement.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

Module Parser::parse() {
  while (index < tokens_size) {
    Token *result = next({Token_t::TOKEN_FLOAT, Token_t::TOKEN_INTEGER,
                          Token_t::TOKEN_HEX, Token_t::TOKEN_OPERATOR});
    std::cout << result->value << std::endl;
  }

  return this->p_module;
}

std::unique_ptr<Expression> Parser::next_expression() {
  Token *token = next({NUMBER_TOKENS, Token_t::TOKEN_OPERATOR});

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