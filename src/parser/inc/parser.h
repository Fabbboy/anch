#include "../../lexer/inc/token.h"
#include "../../lexer/inc/token_t.h"
#include "expression.h"
#include "statement.h"
#include <memory>
#include <vector>
#include "module.h"


#define NUMBER_TOKENS Token_t::TOKEN_FLOAT, Token_t::TOKEN_INTEGER, Token_t::TOKEN_HEX 

class Parser {
public:
  Parser(Token **tokens, size_t tokens_size)
      : tokens_size(tokens_size) {

    this->tokens.reserve(tokens_size);
    for (size_t i = 0; i < tokens_size; i++) {
      this->tokens.push_back(tokens[i]);
    }
  }
  ~Parser() = default;

  Module parse();

private:
  std::vector<Token *> tokens;
  size_t tokens_size;

  int index = 0;

  Token* next(std::vector<Token_t> expected, std::vector<std::string> expected_values = {}); 
  bool peek(std::vector<Token_t> expected, std::vector<std::string> expected_values = {});

  std::unique_ptr<Expression> next_expression();
  std::unique_ptr<Expression> parse_expression();
  int get_precedence(char op);
  std::unique_ptr<Expression> parse_with_precedence(std::unique_ptr<Expression> left, int min_precedence);
};
