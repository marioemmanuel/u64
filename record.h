/* 
   U64 DATABASE
   (C) MARIO EMMANUEL 2024
   record.h
   DATABASE HEADER FILE
   SEE LICENSE FILE FOR LICENSE DETAILS
*/	

#ifndef _U64_RECORD_H
#define _U64_RECORD_H

#include <stddef.h>
#include "db.h"

void create(Database* db, unsigned long key, const unsigned char* value, size_t value_size);
const unsigned char* read(Database* db, unsigned long key, size_t* value_size);
void update(Database* db, unsigned long key, const unsigned char* value, size_t value_size);
void delete(Database* db, unsigned long key);
const unsigned char* read_by_index(Database* db, int index, size_t* value_size);

#endif 

