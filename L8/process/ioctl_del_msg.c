#include "ioctl_operations.h"

int ioctl_delete_msg(int file_desc)
{
  return ioctl_set_msg(file_desc, "deleted_str");
}