#include "inc/token_t.h"

char *token_to_string(Token_t type) {
  switch (type) {
  case TOKEN_INTEGER:
    return "INTEGER";
  case TOKEN_FLOAT:
    return "FLOAT";
  case TOKEN_HEX:
    return "HEX";
  case TOKEN_OPERATOR:
    return "OPERATOR";
  case TOKEN_BRACKETS:
    return "BRACKETS";
  default:
    return "UNKNOWN";
  }
}