
# ============================================================
# Makefile
# Project : Linux Internals
# Topic   : 01 - Linux Architecture
# ============================================================

CC = gcc

TARGET = architecture_01

SRC = linux_20261106_architecture_01.c

CFLAGS = -g -O0 -Wall -Wextra

.PHONY: all run clean

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(SRC)
	 $(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Execute program
run: $(TARGET)
	 ./$(TARGET)

# Remove generated executable
clean:
	 rm -f $(TARGET)



