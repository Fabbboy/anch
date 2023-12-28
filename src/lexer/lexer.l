%option noyywrap
%{
  #include "inc/lexer.h"

  /*
  typedef enum {
  TOKEN_INTEGER,
  TOKEN_FLOAT,
  TOKEN_HEX,
} Token_t;
  */

/*
typedef struct Token {
  char *value;
  Token_t type;
} Token;

Token *token_new(char *value, Token_t type);
void token_free(Token *token);
void token_debug(Token *token);
*/

Token** tokens = NULL;
int token_count = 0;
extern int yylex(void);

void append_token(Token *token) {
  tokens = realloc(tokens, sizeof(Token*) * ++token_count);
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

Token** lex(char *input) {
  yy_scan_string(input);
  yylex();
  return tokens;
}
%}

%%

[ \t\n]+        { /* Skip whitespace. */ }

[0-9]+ {
  Token *token = token_new(yytext, TOKEN_INTEGER);
  append_token(token);
}

[0-9]+\.[0-9]+ {
  Token *token = token_new(yytext, TOKEN_FLOAT);
  append_token(token);
}

0x[0-9a-fA-F]+ {
  Token *token = token_new(yytext, TOKEN_HEX);
  append_token(token);
}
%%