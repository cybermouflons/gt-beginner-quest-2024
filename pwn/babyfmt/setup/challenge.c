#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void setup(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    fflush(stdout);
}   

int main() {
    setup();   

    FILE *fptr;
    char flag[34];
    fptr = fopen("flag.txt", "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    }
    fgets(flag, 34, fptr);

    char fake1[] = "make";
    char fake2[] = "sure";
    char fake3[] = "you";
    char fake4[] = "leak";
    char fake5[] = "allthethings";
    char fmtstr[32] = {0};


    printf("Plese tell us your name number: ");
    read(0, fmtstr, 31);

    printf(fmtstr);

    return 0;

}



    