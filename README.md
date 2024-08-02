# U-64 KEY VALUE DATABASE

(c) MARIO EMMANUEL 2024

## 1. Description

![U-64](U-64.png)

U-64 is a key value database library with the following characteristics:

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

U-64 is a simple but powerful embeddable database. It covers a niche area 
where 64 bits keys suffice.

It is designed to cover by default a 1,000,000 item database, but that value is
configurable.

U-64 was designed as an auxiliary LLM knowledge database for fast retrieval
of indexed resources in RAG environments.

## 3. License

U-64 is provided with dual license capabilities:

AGPL-3 License.
Commercial License.

This repo contains the AGPL-3 License. A commercial license is also available
for commercial applications. Contact the author for more information.

## 4. Database related functions

### 4.1 DB Initialisation

Function `init_db`

**Description**: Initializes the database by setting the size to 0 and the limit to the default value (MAX_SIZE).

**Prototype**: `void init_database(Database* db);`

**Parameters**:
- `db`: A pointer to the `Database` structure to initialize.

### 4.2 Set limit

Function `setlimit_db`

**Description**: Sets the maximum number of items that the database can hold.

**Prototype**: `void setlimit_db(Database* db, int limit);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `limit`: The maximum number of items to set.

### 4.3 Get limit

Function `getlimit_db`

**Description**: Retrieves the current limit of the database.

**Prototype**: `int getlimit_db(Database* db);`

**Parameters**:
- `db`: A pointer to the `Database` structure.

**Returns**: The current limit of the database.

### 4.4 Get number of items in the database

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

Function `create`

**Description**: Creates a new record in the database with the specified key and value.

**Prototype**: `void create(Database* db, unsigned long key, const unsigned char* value, size_t value_size);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `key`: The key for the new record.
- `value`: A pointer to the value to be stored.
- `value_size`: The size of the value in bytes.

### 6.2 Read a record

Function `read`

**Description**: Reads a record from the database by its key.

**Prototype**: `const unsigned char* read(Database* db, unsigned long key, size_t* value_size);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `key`: The key of the record to read.
- `value_size`: A pointer to a variable to store the size of the value.

**Returns**: A pointer to the value if the key is found, `NULL` otherwise.

### 6.3 Update a record

Function `update`

**Description**: Updates an existing record in the database with a new value.

**Prototype**: `void update(Database* db, unsigned long key, const unsigned char* value, size_t value_size);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `key`: The key of the record to update.
- `value`: A pointer to the new value to be stored.
- `value_size`: The size of the new value in bytes.

### 6.4 Delete a record

Function `delete`

**Description**: Deletes a record from the database by its key.

**Prototype**: `void delete(Database* db, unsigned long key);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `key`: The key of the record to delete.

### 6.5 Read index record

Function `read_by_index`

**Description**: Reads a record from the database by its index position.

**Prototype**: `const unsigned char* read_by_index(Database* db, int index, size_t* value_size);`

**Parameters**:
- `db`: A pointer to the `Database` structure.
- `index`: The index position of the record to read.
- `value_size`: A pointer to a variable to store the size of the value.

**Returns**: A pointer to the value if the index is valid, `NULL` otherwise.

## 7. Compiling

`make` will compile the static library libU-64

`make demo` will compile a program named `demo` that shows how to use the library

## 8. Caveats: unsigned long and endianness

As the library is written in ANSI C89, it is not enforced that unsigned long (the type used for keys) will be 64 bits.
However, in almost every modern system (even in 20 years old 32 bit systems) this will be the case. This is also applicable to many modern embedded systems.

For certain special embedded systems unsigned long might be 32 bits, in that case the database will be 32 bits based.

The system does not guarantee portability across systems or compilers for persistence since the persistence is implemented as a memory dump of the database struct.

These limitations are likely not relevant but need to be taken into consideration.

