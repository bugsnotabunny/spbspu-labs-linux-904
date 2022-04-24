#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#include "chardev.h"
#include "ioctl_operations.h"
#include "stdin_input_func.h"

int main()
{
  int file_desc = open(DEVICE_FILE_NAME, 0);
  int ret_val = -1;
  if (file_desc < 0)
  {
    printf("Can't open device file: %s\n", DEVICE_FILE_NAME);
    return ret_val;
  }

  ret_val = 0;
  char inputBuf[BUF_SIZE];
  inputBuf[0] = getchar();
  while (inputBuf[0] != EOF)
  {
    ungetc(inputBuf[0], stdin);
    input_chars(inputBuf, 4, stdin);
    enum IOCtlCommandType commandType = ioctl_get_command_type(inputBuf);
    if (commandType == Nothing)
    {
      return -1;
    }
    else if (commandType == Set)
    {
      input_line(inputBuf, 80, stdin);
      ret_val = ioctl_set_msg(file_desc, inputBuf);
      if (ret_val < 0)
      {
        printf("ioctl_set_msg failed:%d\n", ret_val);
        close(file_desc);
        return ret_val;
      }
    }
    else if (commandType == Get)
    {
      ret_val = ioctl_get_msg(file_desc, inputBuf);
      if (ret_val < 0)
      {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        close(file_desc);
        return ret_val;
      }
      printf("%s\n", inputBuf);
    }
    else if (commandType == Del)
    {
      ioctl_delete_msg(file_desc);
    }
    inputBuf[0] = getchar();
  }
  return ret_val;
}