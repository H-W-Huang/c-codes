#ifndef FILEOPER_H_INCLUDED
#define FILEOPER_H_INCLUDED
#include "datatype.h"

USER * loadFromFile(char * filename);
int saveToFile(char * filename, USER *head);


#endif // FILEOPER_H_INCLUDED
