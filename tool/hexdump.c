#include <stdio.h>
#include <stdlib.h>

#include "hexy.h"
#include "errno.h"

int main(int argc, char *argv[])
{
  if(argc <= 1){
    perror("ERROR: please provide a binary");
    return -ERRNO_NO_FILE_FOUND;
  }

  if(argc >= 3){
    perror("ERROR: to many arguments");
    return -ERRNO_INVALID_ARGS;
  }

  const char* file_name = argv[1];
  
  FILE *file;
  file = fopen(file_name, "rb");

  hexy_dump(file, stdout); 
  
  return ERRNO_SUCCESS;
}
