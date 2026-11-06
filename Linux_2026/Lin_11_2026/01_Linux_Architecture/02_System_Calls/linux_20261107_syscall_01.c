
/*
 * ============================================================
 * File        : linux_20261107_syscall_01.c
 * Topic       : Linux Internals
 * Subtopic    : System Calls - syscall()
 *
 * Description :
 * Demonstrates invoking Linux system calls directly through
 * the syscall() library interface.
 *
 * System Calls:
 *              SYS_getpid
 *              SYS_getppid
 *              SYS_getuid
 *              SYS_geteuid
 *              SYS_write
 *
 * Compile:
 * gcc -g -O0 -Wall -Wextra \
 *     linux_20261107_syscall_01.c -o syscall_01
 * ============================================================
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

static void demonstrate_process_syscalls(void)
{
    long pid;
    long ppid;
    long uid;
    long euid;

    printf("\n========== PROCESS SYSTEM CALLS ==========\n");

    pid = syscall(SYS_getpid);
    ppid = syscall(SYS_getppid);
    uid = syscall(SYS_getuid);
    euid = syscall(SYS_geteuid);

    printf("Process ID        : %ld\n", pid);
    printf("Parent Process ID : %ld\n", ppid);
    printf("User ID           : %ld\n", uid);
    printf("Effective User ID : %ld\n", euid);
}

static void demonstrate_write_syscall(void)
{
    const char message[] =
        "Hello from the Linux kernel interface!\n";

    printf("\n========== WRITE SYSTEM CALL ============\n");

    /*
     * SYS_write invokes the kernel write system call.
     * STDOUT_FILENO represents standard output.
     */
    long result = syscall(
        SYS_write,
        STDOUT_FILENO,
        message,
        sizeof(message) - 1
    );

    if (result == -1)
    {
        perror("syscall write");
        return;
    }

    printf("Bytes written: %ld\n", result);
}

int main(void)
{
    printf("\n========================================\n");
    printf("       LINUX SYSTEM CALL DEMO\n");
    printf("========================================\n");

    demonstrate_process_syscalls();

    demonstrate_write_syscall();

    printf("\n========================================\n");
    printf("       PROGRAM EXECUTION COMPLETE\n");
    printf("========================================\n");

    return 0;
}


