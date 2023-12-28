#include "inc/token.h"
#include <string.h>

Token *token_new(char *value, Token_t type) {
  Token *token = (Token *)malloc(sizeof(Token));
  token->value = strdup(value); // Copy the string to ensure it's persistent.
  token->type = type;
  return token;
};


void token_free(Token *token) {
  free(token->value);
  free(token);
};

void token_debug(Token *token) {
  printf("%s {%s}\n", token_to_string(token->type), token->value);
};