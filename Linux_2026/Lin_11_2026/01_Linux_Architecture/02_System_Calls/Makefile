
# ============================================================
# Makefile
# Project : Linux Internals
# Topic   : 02 - System Calls
# ============================================================

CC = gcc

TARGET = syscall_01

SRC = linux_20261107_syscall_01.c

CFLAGS = -g -O0 -Wall -Wextra

.PHONY: all run trace clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

trace: $(TARGET)
	strace -e trace=getpid,getppid,getuid,geteuid,write ./$(TARGET)

clean:
	rm -f $(TARGET)


