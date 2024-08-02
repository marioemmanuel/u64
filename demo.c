/* 
   U64 DATABASE
   (C) MARIO EMMANUEL 2024
   demo.c
   DEMO FILE
   SEE LICENSE FILE FOR LICENSE DETAILS
*/	

#include "db.h"
#include "persistence.h"
#include <stdio.h>

int main() {
	size_t i;
    Database db;
    init_database(&db);
    
	printf("Size before creating item 1: %d\n", getsize_db(&db));

    unsigned char value1[] = {0x01, 0x02, 0x03, 0x04};
    create(&db, 100, value1, sizeof(value1));
	
	printf("Size after creating item 100: %d\n", getsize_db(&db));
    
    unsigned char value2[] = {0x11, 0x12, 0x13, 0x14};
    create(&db, 200, value2, sizeof(value2));
	
	printf("Size after creating item 200: %d\n", getsize_db(&db));

    size_t size;
    const unsigned char* read_value = read(&db, 100, &size);
    if (read_value) {
        printf("Read key 100: ");
        for (i = 0; i < size; i++) {
            printf("%02x ", read_value[i]);
        }
        printf("\n");
    }

    unsigned char value3[] = {0x21, 0x22, 0x23};
    update(&db, 100, value3, sizeof(value3));

    read_value = read(&db, 100, &size);
    if (read_value) {
        printf("Read key 1 after update: ");
        for (i = 0; i < size; i++) {
            printf("%02x ", read_value[i]);
        }
        printf("\n");
    }

    delete(&db, 100);

    printf("Size after delete: %d\n", getsize_db(&db));

    const unsigned char* read_index_value = read_by_index(&db, 0, &size);
    if (read_index_value) {
        printf("Read by index 0: ");
        for (i = 0; i < size; i++) {
            printf("%02x ", read_index_value[i]);
        }
        printf("\n");
    }

    write_db(&db, "database.dat");

    Database db2;
    init_database(&db2);
    read_db(&db2, "database.dat");

    printf("Size of db2 after reading from file: %d\n", getsize_db(&db2));

    return 0;
}