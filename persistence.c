/* 
   U64 DATABASE
   (C) MARIO EMMANUEL 2024
   persistence.c
   PERSITENCE RELATED FUNCTIONS
   SEE LICENSE FILE FOR LICENSE DETAILS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

int read_db(Database* db, const char* filename) {
    int i;
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return -1;
    }

    fread(&db->size, sizeof(int), 1, file);
    fread(db->keys, sizeof(unsigned long), db->size, file);
    fread(db->value_sizes, sizeof(size_t), db->size, file);

    for (i = 0; i < db->size; ++i) {
        db->values[i] = (unsigned char*)malloc(db->value_sizes[i]);
        fread(db->values[i], sizeof(unsigned char), db->value_sizes[i], file);
    }

    fclose(file);
    return 0;
}

int write_db(Database* db, const char* filename) {
    int i;
    FILE* file = fopen(filename, "wb");
    if (!file) {
        return -1;
    }

    fwrite(&db->size, sizeof(int), 1, file);
    fwrite(db->keys, sizeof(unsigned long), db->size, file);
    fwrite(db->value_sizes, sizeof(size_t), db->size, file);

    for (i = 0; i < db->size; ++i) {
        fwrite(db->values[i], sizeof(unsigned char), db->value_sizes[i], file);
    }

    fclose(file);
    return 0;
}
