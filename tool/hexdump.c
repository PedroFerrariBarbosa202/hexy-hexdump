#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "hexy.h"
#include "errno.h"

#define FLAG_BYTE_PER_LINE (1 << 0)

static hexy_config_t config = {
  .bytes_per_line = 16,
};

static void parse_cli(int argc, char *argv[]){
  uint8_t flags = 0;
  
  int opt;
  while((opt = getopt(argc, argv, "w:")) != -1){
    switch(opt){
      case 'w':{
          flags |= FLAG_BYTE_PER_LINE;
          config.bytes_per_line = atoi(optarg);
      }break;
    }
  }

  config.flags = flags;
}

int main(int argc, char *argv[])
{
  if(argc < 1){
    puts("Error: to little arguments");
    return -ERRNO_INVALID_ARGS;
  }
  
  parse_cli(argc, argv);

  if(optind >= argc){
    puts("Error: no file found");
    return -ERRNO_NO_FILE_FOUND;
  }

  const char* file_name = argv[optind];
  
  FILE *file;
  file = fopen(file_name, "rb");

  if (file == NULL) {
    perror(file_name);
    return -ERRNO_NO_FILE_FOUND;
  }

  hexy_dump(file, stdout, &config);

  fclose(file);
  
  return ERRNO_SUCCESS;
}
