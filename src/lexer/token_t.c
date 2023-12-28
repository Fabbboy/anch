#include "inc/token_t.h"

char *token_to_string(Token_t type) {
  switch (type) {
  case TOKEN_INTEGER:
    return "INTEGER";
  default:
    return "UNKNOWN";
  }
};
