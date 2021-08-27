#ifndef WORD_PARSER_H
#define WORD_PARSER_H

#include <stdint.h>
typedef struct Word {
  char * data;
  int count;

  Word ( char * data_ ) :
    data( ::strdup(data_) )
  {}
  
  Word () :
    data((char *)"")
  {}
} Word;

#endif //WORD_PARSER_H