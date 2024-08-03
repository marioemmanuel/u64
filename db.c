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

void init_db(Database* db, int limit) {
    db->size = 0;
    db->limit = (size_t) limit;
    db->keys = (unsigned long *)malloc(sizeof(unsigned long)*db->limit);
    db->values = (unsigned char **)malloc(sizeof(unsigned char *)*db->limit);
    db->value_sizes = (size_t *)malloc(sizeof(size_t)*db->limit);
    if(db->keys == NULL || db->values == NULL || db->value_sizes == NULL) {
        fprintf(stderr, "ERROR init_db: Can not allocate memory");
        exit(-1);
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

