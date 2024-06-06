// suid read /flag.txt
// gcc -o readflag readflag.c
// chmod 4755 readflag
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd = open("/flag.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buf[100];
    ssize_t n = read(fd, buf, sizeof(buf));
    if (n < 0) {
        perror("read");
        return 1;
    }

    write(1, buf, n);
    return 0;
}
