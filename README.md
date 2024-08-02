# u64 KEY VALUE DATABASE

(c) MARIO EMMANUEL 2024

## 1. Description

u64 is a key value database library with the following characteristics:

- Written in strict ANSI C89 (highly portable).
- No dependecies on external libraries.
- Single threaded (intended to be embeddable with another processes).
- Simple and lightweight.
- Fast and performant through sorted storage of database items.
- Keys are unsigned long 64 bits.
- Values are arbitrary length of bytes.
- Commands and outputs via stdin and stdout (intended to be used as embbeded 
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

It is designed to cover by default a 1.000.000 item database, but that value is
configurable.

u64 was designed as an auxiliary LLM knowledge database for fast retrieval
of indexed resources in RAG environments.

## 3. License

u64 is provided with dual license capabilities:

AGPL-3 License.
Commercial License.

This repo contains the AGPL-3 License. A commercial license is also available
for commercial applications. Contact the author for more information.

## 4. Database related functions

### 4.1 Set limit

Function setlimit_db

### 4.2 Get limit

Function getlimit_db

### 4.3 Get number of items in the database

Function getsize_db

## 5. Persistence related functions

### 5.1 Read Database

Function read_db

### 5.2 Write Database

Function write_db

## 6. Record related functions

### 6.1 Create a record

Function create

### 6.2 Read a record

Function read

### 6.3 Update a record

Function update

### 6.4 Delete a record

Function delete

### 6.5 Read index record

Function read_index

## 7. Compiling

make will compile the static library libu64

make demo will compile a program named demo that shows how to use the library

## 8. Caveats: unsigned long and endianness

As the library is written in ANSI C89, it is not enforced that unsigned long (the type used for keys) will be 64 bits.
However, in almost every modern system (even in 20 years old 32 bit systems) this will be the case. This is also applicable to many modern embedded systems.

For certain special embedded systems unsigned long might be 32 bits, in that case the database will be 32 bits based.

The system does not warranty portability across systems or compilers for persistence since the persistence is implemented as a memory dump of the databse struct.

These limitations are likely not relevant but need to be taken into consideration.
