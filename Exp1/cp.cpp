#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

int main(int argc, char **argv)
{
    int fd_in, fd_out;
    char s[SIZE];
    if (argc != 3) {
        puts("Input error");
        exit(-1);
    }
    fd_in = open(argv[1], O_RDONLY);
    if (fd_in == -1) {
        puts("File not found");
        exit(-1);
    }

    fd_out = open(argv[2], O_WRONLY | O_CREAT, 0644);
    if (fd_out == -1) {
        puts("create file failed");
        exit(-1);
    }
    int size, size_write;
    while ((size = read(fd_in, s, SIZE)) != 0) {
        if (size < 0) {
            puts("read failed");
            exit(-1);
        }
        size_write=write(fd_out, s, size);
        if (size_write == 0) {
            break;
        }
        if (size_write < 0) {
            puts("write failed");
            exit(-1);
        }
    }
    close(fd_in);
    close(fd_out);
}