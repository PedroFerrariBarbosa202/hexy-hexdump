#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "format.h"

error_t format_buffer(hexy_format_t *format, hexy_config_t *config){
  int offset = format->offset;

  fprintf(format->output, "%08x | ", offset);
  
  for(int i = 0; i < config->bytes_per_line; i++){
    if(i < format->length){
      fprintf(format->output, "%02X ", format->buffer[i]);
    }else{
      fprintf(format->output, "   ");
    }
  }
  
  fprintf(format->output, " | ");

  for (size_t i = 0; i < config->bytes_per_line; i++) {
        unsigned char c = format->buffer[i];

        fputc(isprint(c) ? c : '.', format->output);
    }

  fprintf(format->output, "\n");

  return ERRNO_SUCCESS;
}
