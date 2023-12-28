#pragma once
#include "../../preproc.h"

CXXBEGIN
typedef enum Token_t{
  //VALUES
  TOKEN_INTEGER = 0,
} Token_t;

char* token_to_string(Token_t type);
CXXEND