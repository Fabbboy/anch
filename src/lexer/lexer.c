#include "inc/lexer.h"

Token **tokens = NULL;
int token_count = 0;
extern int yylex(void);
extern int yy_scan_string(char *str);

Token **lex(char *input) {
  free_tokens();
  tokens = malloc(sizeof(Token *));
  yy_scan_string(input);
  yylex();
  return tokens;
}

void append_token(Token *token) {
  tokens = realloc(tokens, sizeof(Token *) * ++token_count);
  tokens[token_count - 1] = token;
}

void free_tokens() {
  while (token_count > 0) {
    token_free(tokens[--token_count]);
  }
  free(tokens);
}

void debug_tokens() {
  for (int i = 0; i < token_count; i++) {
    token_debug(tokens[i]);
  }
}