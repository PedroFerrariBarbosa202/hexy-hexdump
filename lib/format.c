#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "format.h"

#define FORMAT_HEX    ("%02X ")
#define FORMAT_OCT    ("%03o ")

error_t format_buffer(hexy_format_t *format, hexy_config_t *config){
  int offset = format->offset;

  fprintf(format->output, "%08x | ", offset);

  char *format_string = (config->flags & FLAG_BYTE_OCTAL) ? FORMAT_OCT : FORMAT_HEX;
  
  for(int i = 0; i < config->bytes_per_line; i++){
    if(i < format->length){
      fprintf(format->output, format_string, format->buffer[i]);
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
