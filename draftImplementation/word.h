#ifndef WORD_H
#define WORD_H

#include <stdint.h>
typedef struct Word {
  char data[33];
  int count;

  //Word ( char * data_ ) :
  //  data( ::_strdup(data_) ), count(0)
  //{}
  //
  //Word () :
  //  data((char *)""), count(0)
  //{}
} Word;

#endif //WORD_H