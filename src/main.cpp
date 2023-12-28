#include <iostream>
#include "lexer/inc/lexer.h"
#include <fstream>

#define TESTING 0

#define READ_CONTENTS(FILE_PATH) std::ifstream file(FILE_PATH); \
  std::string contents((std::istreambuf_iterator<char>(file)), \
  std::istreambuf_iterator<char>()); \
  file.close();

#ifdef TESTING
static std::string tests[] = {
  "tests/simple/num_n_op.anch"
};
int main() {
  for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
    std::cout << "==== Testing: " << tests[i] << " ====" << std::endl;
    READ_CONTENTS(tests[i]);
    if (contents.empty()) {
      std::cout << "File is empty" << std::endl;
      return 1;
    }
    char* input_c = (char*)contents.c_str();
    Token** tokens = lex(input_c);

    for (int i = 0; i < token_count; i++) {
      token_debug(tokens[i]);
    }
  }
  return 0;
}
#else 
int main(){
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
#endif