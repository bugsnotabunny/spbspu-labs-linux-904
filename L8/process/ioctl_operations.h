#ifndef IOCTL_SET_MSG_H
#define IOCTL_SET_MSG_H

#include "chardev.h"

enum IOCtlCommandType
{
  Nothing = 0,
  Set,
  Get,
  Del
};

enum IOCtlCommandType ioctl_get_command_type(const char* call);

int ioctl_set_msg(int file_desc, char* message);
int ioctl_get_msg(int file_desc, char* buf);
int ioctl_delete_msg(int file_desc);

#endif