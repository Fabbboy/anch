%option noyywrap
%{
  #include "inc/lexer.h"
  /*
  typedef enum {
  TOKEN_INTEGER,
  TOKEN_FLOAT,
  TOKEN_HEX,

  TOKEN_OPERATOR,
  TOKEN_BRACKET
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
%}


%%

[ \t\n]+        { /* Skip whitespace. */ }

[+-]?[0-9]+ {
  APPEND(TOKEN_INTEGER)
}

[+-]?[0-9]+\.[0-9]+ {
  APPEND(TOKEN_FLOAT)
}

[+-]?\.[0-9]+ {
  APPEND(TOKEN_FLOAT)
}

0x[0-9a-fA-F]+ {
  APPEND(TOKEN_HEX)
}

[+\-*/%] {
  APPEND(TOKEN_OPERATOR)
}

[\(\)\[\]\{\}] {
  APPEND(TOKEN_BRACKET)
}
%%