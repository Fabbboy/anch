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

#ifdef __cplusplus
}
#endif
