#ifndef INCLUDEhexyformatformat.h_
#define INCLUDEhexyformatformat.h_

#include "errno.h"
#include <stdint.h>

typedef struct hexy_config_t{
  uint8_t flags;
  uint32_t bytes_per_line;
}hexy_config_t;

typedef struct hexy_format_t{
  FILE *output;
  int offset;
  const uint8_t* buffer;
  int length;
}hexy_format_t;

error_t format_buffer(hexy_format_t *format, hexy_config_t *config);

#endif  // INCLUDEhexyformatformat.h_
