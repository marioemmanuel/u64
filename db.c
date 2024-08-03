/* 
   U64 DATABASE
   (C) MARIO EMMANUEL 2024
   db.c
   DATABASE RELATED FUNCTIONS
   SEE LICENSE FILE FOR LICENSE DETAILS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

void init_db(Database* db) {
    db->size = 0;
    db->limit = MAX_SIZE;
}

void setlimit_db(Database* db, int limit) {
    if (limit > 0 && limit <= MAX_SIZE) {
        db->limit = limit;
    }
}

int getlimit_db(Database* db) {
    return db->limit;
}

int getsize_db(Database* db) {
    return db->size;
}

int binary_search_db(Database* db, unsigned long key) {
    int low = 0, high = db->size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (db->keys[mid] == key) {
            return mid;
        } else if (db->keys[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

