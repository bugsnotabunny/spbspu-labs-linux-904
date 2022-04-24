#ifndef STDIN_INPUT_FUNC_H
#define STDIN_INPUT_FUNC_H

#include <stdio.h>
#include <stddef.h>

void input_chars(char* buf, size_t count, FILE * stream);
void input_line(char* buf, size_t maxCount, FILE * stream);

#endif