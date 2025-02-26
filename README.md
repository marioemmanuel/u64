# u64 KEY VALUE DATABASE

(c) Mario Emmanuel 2024

## 1. Description

u64 is a key value database library with the following characteristics. It is named after the type used 
for the keys (unsigned long 64 bits).

- Written in strict ANSI C89 (highly portable).
- No dependencies on external libraries.
- Single threaded (intended to be embeddable with another processes).
- Simple and lightweight.
- Fast and performant through sorted storage of database items.
- Keys are unsigned long 64 bits.
- Values are arbitrary length of bytes.
- Commands and outputs via stdin and stdout (intended to be used as embedded 
  database in systems).
- Front end for testing available.
- Four CRUD operations implemented as main commands: Create/Read/Update/Delete.
- Two operations implemented to allow to iterate over items: ReadByIndex and 
  GetSize.
- Two operations implemented to provide persistence via snapshots: ReadDatabase
  and WriteDatabase.

## 2. Audience

u64 is a simple but powerful embeddable database. It covers a niche area 
where 64 bits keys suffice.

u64 was designed as an auxiliary LLM knowledge database for fast retrieval
of indexed resources in RAG environments.

## 3. License

u64 is provided with dual license capabilities:

AGPL-3 License.
Commercial License.

This repo contains the AGPL-3 License. A commercial license is also available
for commercial applications. Contact the author for more information.

Images are not covered by this license.

## 4. Database related functions

### 4.1 DB Initialisation

Function `init_db`

**Description**: Initializes the database by setting the size to 0 and the limit to the provided value.

**Prototype**: `void init_database(Database* db, int limit);`

**Parameters**:
- `db`: A pointer to the `Database` structure to initialize.
- `limit`: An int specifying the preallocated space in the Database to store items.

### 4.2 Get limit

Function `getlimit_db`

**Description**: Retrieves the current limit of the database.

**Prototype**: `int getlimit_db(Database* db);`

**Parameters**:
- `db`: A pointer to the `Database` structure.

**Returns**: The current limit of the database.

### 4.3 Get number of items in the database

Function `getsize_db`

**Description**: Gets the number of items currently stored in the database.

**Prototype**: `int getsize_db(Database* db);`

**Parameters**:
- `db`: A pointer to the `Database` structure.

**Returns**: The number of items in the database.

## 5. Persistence related functions

### 5.1 Read Database

Function `read_db`

**Description**: Reads the database from a file and populates the database structure.

**Prototype**: `int read_db(Database* db, const char* filename);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `filename`: The name of the file to read the database from.

**Returns**: `0` on success, `-1` on failure.

### 5.2 Write Database

Function `write_db`

**Description**: Writes the current state of the database to a file.

**Prototype**: `int write_db(Database* db, const char* filename);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `filename`: The name of the file to write the database to.

**Returns**: `0` on success, `-1` on failure.

## 6. Record related functions

### 6.1 Create a record

Function `create_record`

**Description**: Creates a new record in the database with the specified key and value.

**Prototype**: `void create_record(Database* db, unsigned long key, const unsigned char* value, size_t value_size);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `key`: The key for the new record.
- `value`: A pointer to the value to be stored.
- `value_size`: The size of the value in bytes.

### 6.2 Read a record

Function `read_record`

**Description**: Reads a record from the database by its key.

**Prototype**: `const unsigned char* read_record(Database* db, unsigned long key, size_t* value_size);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `key`: The key of the record to read.
- `value_size`: A pointer to a variable to store the size of the value.

**Returns**: A pointer to the value if the key is found, `NULL` otherwise.

### 6.3 Update a record

Function `update_record`

**Description**: Updates an existing record in the database with a new value.

**Prototype**: `void update_record(Database* db, unsigned long key, const unsigned char* value, size_t value_size);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `key`: The key of the record to update.
- `value`: A pointer to the new value to be stored.
- `value_size`: The size of the new value in bytes.

### 6.4 Delete a record

Function `delete`

**Description**: Deletes a record from the database by its key.

**Prototype**: `void delete_record(Database* db, unsigned long key);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `key`: The key of the record to delete.

### 6.5 Read index record

Function `read_by_index_record`

**Description**: Reads a record from the database by its index position.

**Prototype**: `const unsigned char* read_by_index_record(Database* db, int index, size_t* value_size);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `index`: The index position of the record to read.
- `value_size`: A pointer to a variable to store the size of the value.

**Returns**: A pointer to the value if the index is valid, `NULL` otherwise.

## 7. Compiling

`make` will compile the static library libu64

`make demo` will compile a program named `demo` that shows how to use the library

`make man` will install the man page `libu64` in section 3.

## 8. Caveats: unsigned long and endianness

As the library is written in ANSI C89, it is not enforced that unsigned long (the type used for keys) will be 64 bits.
However, in almost every modern system (even in 20 years old 32 bit systems) this will be the case. This is also applicable to many modern embedded systems.

For certain special embedded systems unsigned long might be 32 bits, in that case the database will be 32 bits based.

The system does not guarantee portability across systems or compilers for persistence since the persistence is implemented as a memory dump of the database struct.

These limitations are likely not relevant but need to be taken into consideration.

## 9. About the name / Trivia

The database is named after the fact that it uses 64 bits unsigned long as keys.

The U-64 was also a Kriegsmarine U-Boat sunk during the invasion of Denmark and Norway (Operation Weserübung) during WWII.

![u64](u64.jpg)
