#pragma once
#include "../../preproc.h"

CXXBEGIN
typedef enum Token_t{
  //VALUES
  TOKEN_INTEGER = 0,
  TOKEN_FLOAT,
  TOKEN_HEX,
} Token_t;

char* token_to_string(Token_t type);
CXXEND