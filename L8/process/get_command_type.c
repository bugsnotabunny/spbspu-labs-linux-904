#include "ioctl_operations.h"

#include <stddef.h>
#include <stdbool.h>

enum IOCtlCommandType ioctl_get_command_type(const char* call)
{
  static const char* const SET = "set";
  static const char* const GET = "get";
  static const char* const DEL = "del";
  char isLikelyToBe = Nothing;
  size_t i = 0;

  if (call[i] == SET[i])
  {
    isLikelyToBe = Set;
  }
  else if (call[i] == GET[i])
  {
    isLikelyToBe = Get;
  }
  else if (call[i] == DEL[i])
  {
    isLikelyToBe = Del;
  }
  ++i;

  if (isLikelyToBe == Get)
  {
    while (i < 3)
    {
      if (call[i] != GET[i])
      {
        break;;
      }
      ++i;
    }
    return Get;
  }
  else if (isLikelyToBe == Set)
  {
    while (i < 3)
    {
      if (call[i] != SET[i])
      {
        break;
      }
      ++i;
    }
    return Set;
  }
  else if (isLikelyToBe == Del)
  {
    while (i < 3)
    {
      if (call[i] != DEL[i])
      {
        break;
      }
      ++i;
    }
    return Del;
  }
  return Nothing;
}