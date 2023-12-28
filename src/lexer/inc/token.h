#pragma once
#include "../../preproc.h"

CXXBEGIN
#include "token_t.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Token {
  char *value;
  Token_t type;
} Token;

Token *token_new(char *value, Token_t type);
void token_free(Token *token);
void token_debug(Token *token);
CXXEND