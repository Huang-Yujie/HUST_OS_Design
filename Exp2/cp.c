#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        puts("Input error");
        exit(-1);
    }
	syscall(335, argv[1], argv[2]);
	return 0;
}