#include "ioctl_operations.h"

#include <stdio.h>
#include <sys/ioctl.h>

int ioctl_set_msg(int file_desc, char* message)
{
  return ioctl(file_desc, IOCTL_SET_MSG, message);
}