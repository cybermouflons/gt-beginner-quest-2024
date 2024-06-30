#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void setup() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main(void) {
    setup();

    puts("\nWelcome young recruit. Enter your name in the box below and wait to see if you are granted access: ");

    printf(
        "╔══════════════════════════════════════════════════╗\n"
        "║                                                  ║\n"
        "╚══════════════════════════════════════════════════╝"
    );
    printf("\033[1F");
    printf("\033[2C");

    char input[48];
    gets(input);

    puts("");
}
