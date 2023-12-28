#include "../../lexer/inc/token.h"
#include "../../lexer/inc/token_t.h"
#include "statement.h"
#include <memory>
#include <vector>

class Module {
public:
  Module() {};
  ~Module() = default;

  void add_statement(std::shared_ptr<Statement> statement) {
    this->statements.push_back(std::move(statement));
  }

private:
  std::vector<std::shared_ptr<Statement>> statements;
};

class Parser {
public:
  Parser(Token **tokens, size_t tokens_size)
      : first_tokens(tokens), tokens_size(tokens_size), p_module() {}
  ~Parser() = default;

  Module parse();

private:
  Module p_module;
  Token **first_tokens;
  size_t tokens_size;
};
