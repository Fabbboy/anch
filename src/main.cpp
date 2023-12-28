#include "lexer/inc/lexer.h"
#include "parser/inc/parser.h"
#include <fstream>
#include <iostream>
#define TESTING 0

#ifdef TESTING
static std::string tests[] = {
    "tests/simple/num_n_op.anch",
    "tests/simple/simple_op.anch",
};
int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
    std::cout << "==== Testing: " << tests[i] << " ====" << std::endl;
    std::ifstream file(tests[i]);
    std::string contents((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
    if (contents.empty()) {
      std::cout << "File is empty" << std::endl;
      continue;
    }
    char *input_c = (char *)contents.c_str();
    Token **tokens = lex(input_c);

    for (int i = 0; token_count > i; i++) {
      token_debug(tokens[i]);
    }

    std::cout << "==== Parsing: " << tests[i] << " ====" << std::endl;

    Parser parser(tokens, token_count);
    Module module = parser.parse();
  }
  return 0;
}
#else
int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
#endif