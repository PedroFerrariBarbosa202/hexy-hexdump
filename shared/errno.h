#ifndef ERRNO_H
#define ERRNO_H

typedef enum error_t{
#define ERROR(errno) errno, 
  #include "details/errno.inc"
#undef ERROR 

  ERRNO_LIST_LENGTH
}error_t;

static const char *error_as_string(error_t error)
{
    switch (error) {
#define ERROR(errno) case errno: return #errno;
  #include "details/errno.inc"
#undef ERROR
      case ERRNO_LIST_LENGTH: return "ERROR_LIST_LENGTH";
    }

    return "ERROR_FAILED_STRING_CONVERSION";
}

#endif 
