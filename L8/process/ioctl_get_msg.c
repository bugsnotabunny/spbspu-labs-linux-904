#include "ioctl_operations.h"

#include <stdio.h>
#include <sys/ioctl.h>

int ioctl_get_msg(int file_desc, char* buf)
{
  return ioctl(file_desc, IOCTL_GET_MSG, buf);
}