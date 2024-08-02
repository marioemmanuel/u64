/* 
   U64 DATABASE
   (C) MARIO EMMANUEL 2024
   record.c
   RECORD RELATED FUNCTIONS
   SEE LICENSE FILE FOR LICENSE DETAILS
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.h"

void create(Database* db, unsigned long key, const unsigned char* value, size_t value_size) {

	int i;

    if (db->size >= db->limit) {
        printf("Database is full\n");
        return;
    }

    int index = binary_search(db, key);

    if (index < db->size && db->keys[index] == key) {
        printf("Key already exists\n");
        return;
    }

    for (i = db->size; i > index; --i) {
        db->keys[i] = db->keys[i - 1];
        db->values[i] = db->values[i - 1];
        db->value_sizes[i] = db->value_sizes[i - 1];
    }

    db->keys[index] = key;
    db->values[index] = (unsigned char*)malloc(value_size);
    memcpy(db->values[index], value, value_size);
    db->value_sizes[index] = value_size;
    db->size++;
}

const unsigned char* read(Database* db, unsigned long key, size_t* value_size) {
    int index = binary_search(db, key);
    if (index < db->size && db->keys[index] == key) {
        *value_size = db->value_sizes[index];
        return db->values[index];
    }
    return NULL;
}

void update(Database* db, unsigned long key, const unsigned char* value, size_t value_size) {
    int index = binary_search(db, key);
    if (index < db->size && db->keys[index] == key) {
        free(db->values[index]);  /* Free the old value memory */
        db->values[index] = (unsigned char*)malloc(value_size);
        memcpy(db->values[index], value, value_size);
        db->value_sizes[index] = value_size;
    } else {
        printf("Key not found\n");
    }
}

void delete(Database* db, unsigned long key) {
	int i;
    int index = binary_search(db, key);
    if (index < db->size && db->keys[index] == key) {
        free(db->values[index]);  /* Free the value memory */
        for (i = index; i < db->size - 1; ++i) {
            db->keys[i] = db->keys[i + 1];
            db->values[i] = db->values[i + 1];
            db->value_sizes[i] = db->value_sizes[i + 1];
        }
        db->size--;
    } else {
        printf("Key not found\n");
    }
}

const unsigned char* read_by_index(Database* db, int index, size_t* value_size) {
    if (index >= 0 && index < db->size) {
        *value_size = db->value_sizes[index];
        return db->values[index];
    }
    return NULL;
}
