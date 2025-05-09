#pragma once
#include "libc/stdint.h"

size_t strlen(const char* str);
char* hex32_to_str(char buffer[], unsigned int val);
char* int32_to_str(char buffer[], int val);
