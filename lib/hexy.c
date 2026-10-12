#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "hexy.h"

error_t hexy_dump(FILE *input, FILE *output, hexy_config_t *config){
  uint8_t hex_buff[config->bytes_per_line];
  size_t bytes_read;
  size_t offset = 0;

  while((bytes_read = fread(hex_buff, 1, config->bytes_per_line, input)) > 0){
    hexy_format_t format = {
      .output = output,
      .offset = offset,
      .buffer = hex_buff,
      .length = bytes_read, 
    };
    format_buffer(&format, config);

    offset += bytes_read;
  }

  return ERRNO_SUCCESS;
}

