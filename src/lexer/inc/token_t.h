#pragma once
#include "../../preproc.h"

CXXBEGIN
typedef enum Token_t{
  //VALUES
  TOKEN_INTEGER = 0,
  TOKEN_FLOAT,
  TOKEN_HEX,

  //OPERATORS
  TOKEN_OPERATOR,
} Token_t;

char* token_to_string(Token_t type);
CXXEND