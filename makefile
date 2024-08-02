# U64 DATABASE
# (C) MARIO EMMANUEL 2024
# makefile
# SEE LICENSE FILE FOR LICENSE DETAILS

# Target library and binary
LIBRARY = libu64.a
TARGET = demo

# Source files
SRCS = db.c record.c persistence.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -std=c89 -Wall

# Header files
HEADERS = db.h record.h persistence.h

# Build the static library
$(LIBRARY): $(OBJS)
	ar rcs $(LIBRARY) $(OBJS)

# Build the demonstration program
$(TARGET): $(LIBRARY) demo.o
	$(CC) $(CFLAGS) -o $(TARGET) demo.o $(LIBRARY)

# Compile source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build artifacts
clean:
	rm -f $(TARGET) $(LIBRARY) $(OBJS) demo.o

# Phony targets
.PHONY: all clean

# Default target
all: $(LIBRARY) $(TARGET)

