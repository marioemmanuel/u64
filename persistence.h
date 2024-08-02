/* 
   U64 DATABASE
   (C) MARIO EMMANUEL 2024
   persistence.h
   PERSISTENCE HEADER FILE
   SEE LICENSE FILE FOR LICENSE DETAILS
*/	

#ifndef _U64_PERSISTENCE_H
#define _U64_PERSISTENCE_H

#include "db.h"

int read_db(Database* db, const char* filename);
int write_db(Database* db, const char* filename);

#endif 

