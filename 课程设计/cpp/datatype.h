#ifndef DATATYPE_H_INCLUDED
#define DATATYPE_H_INCLUDED

struct user
{
    int id;
    char name[20];
    char password[20];
};

typedef struct user USER;

#endif // DATATYPE_H_INCLUDED
