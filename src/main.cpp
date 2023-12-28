#include <iostream>
#include "lexer/inc/lexer.h"

int main() {
  std::string input = R"(21
   23
    12)";
  char* input_c = (char*)input.c_str();
  Token** tokens = lex(input_c);

  for (int i = 0; i < token_count; i++) {
    token_debug(tokens[i]);
  }

  return 0;
}