#include "inc/token_t.h"

char *token_to_string(Token_t type) {
  switch (type) {
  case TOKEN_INTEGER:
    return "INTEGER";
  case TOKEN_FLOAT:
    return "FLOAT";
  case TOKEN_HEX:
    return "HEX";
  default:
    return "UNKNOWN";
  }
}