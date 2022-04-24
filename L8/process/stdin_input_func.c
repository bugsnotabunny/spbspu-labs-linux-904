#include "stdin_input_func.h"

void input_chars(char* buf, size_t count, FILE * stream)
{
  size_t i = 0;
  while (i < count)
  {
    buf[i] = getc(stream);
    ++i;
  }
  buf[i] = '\0';
}

void input_line(char* buf, size_t maxCount, FILE * stream)
{
  size_t i = 0;
  char charBuf = getc(stream);
  while (charBuf != '\n' && charBuf != EOF && i < maxCount - 1)
  {
    buf[i] = charBuf;
    charBuf = getc(stream);
    ++i;
  }
  buf[i] = '\0';
}
