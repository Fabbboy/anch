#pragma once

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token_t.h"
#include "token.h"


void append_token(Token *token);
void free_tokens();
void debug_tokens();
Token** lex(char *input);

extern Token** tokens;
extern int token_count;

#define APPEND(TYPE) Token *token = token_new(yytext, TYPE); \
  append_token(token);

#ifdef __cplusplus
}
#endif
