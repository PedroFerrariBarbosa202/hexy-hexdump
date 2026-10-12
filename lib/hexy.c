#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "format.h"

#define BUFFER_SIZE (16)

error_t hexy_dump(FILE *input, FILE *output){
  uint8_t hex_buff[BUFFER_SIZE];
  size_t bytes_read;
  size_t offset = 0;

  while((bytes_read = fread(hex_buff, 1, 16, input)) > 0){
    hexy_format_t format = {
      .output = output,
      .offset = offset,
      .buffer = hex_buff,
      .length = bytes_read   
    };
    format_buffer(&format);

    offset += bytes_read;
  }

  return ERRNO_SUCCESS;
}

