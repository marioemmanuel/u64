/* 
   U64 DATABASE
   (C) MARIO EMMANUEL 2024
   db.h
   DATABASE HEADER FILE
   SEE LICENSE FILE FOR LICENSE DETAILS
*/  

#ifndef _U64_DATABASE_H
#define _U64_DATABASE_H

#include <stddef.h>

typedef struct {
    unsigned long *keys;
    unsigned char **values;
    size_t *value_sizes;
    int size;
    int limit;
} Database;

void init_db(Database* db, int limit);
int getlimit_db(Database* db);
int getsize_db(Database* db);
int binary_search_db(Database* db, unsigned long key);

#endif 

