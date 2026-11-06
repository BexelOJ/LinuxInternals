
/*
 * ============================================================
 * File        : linux_20261106_architecture_01.c
 * Topic       : Linux Architecture
 * Subtopic    : Kernel Space vs User Space
 *
 * Description :
 * Demonstrates the separation between user space and kernel
 * space by retrieving kernel and process information.
 *
 * APIs        :
 *              uname()
 *              getpid()
 *              getppid()
 *              getuid()
 *              geteuid()
 *
 * Compile     :
 * gcc -g -O0 -Wall -Wextra \
 *     linux_20261106_architecture_01.c -o architecture_01
 * ============================================================
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>

static void display_kernel_information(void)
{
    struct utsname system_info;

    printf("\n========== KERNEL INFORMATION ==========\n");

    if (uname(&system_info) == -1)
    {
        perror("uname");
        return;
    }

    printf("Operating System : %s\n", system_info.sysname);
    printf("Hostname         : %s\n", system_info.nodename);
    printf("Kernel Release   : %s\n", system_info.release);
    printf("Kernel Version   : %s\n", system_info.version);
    printf("Machine          : %s\n", system_info.machine);
}

static void display_process_information(void)
{
    printf("\n========== USER SPACE INFORMATION ======\n");

    printf("Process ID       : %ld\n", (long)getpid());
    printf("Parent Process ID: %ld\n", (long)getppid());

    printf("User ID          : %ld\n", (long)getuid());
    printf("Effective User ID: %ld\n", (long)geteuid());
}

static void demonstrate_user_space(void)
{
    int number1 = 100;
    int number2 = 200;

    printf("\n========== USER SPACE OPERATION ========\n");

    printf("Number 1         : %d\n", number1);
    printf("Number 2         : %d\n", number2);
    printf("Addition         : %d\n", number1 + number2);

    printf("This calculation executes in user space.\n");
}

int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf("       LINUX ARCHITECTURE DEMO\n");
    printf("========================================\n");

    demonstrate_user_space();

    display_kernel_information();

    display_process_information();

    printf("\n========================================\n");
    printf("       PROGRAM EXECUTION COMPLETE\n");
    printf("========================================\n");

    return 0;
}



