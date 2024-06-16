// gcc -g -no-pie -o chal challenge.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setup(){
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    fflush(stdout);
}

void pretty_train(){
    printf("Oxy needs my help with cracking some passwords.\nIt will take only 5 minutes to get to their place with this fast train.\nHere comes the train conductor...\n");

    char train[] = "____\n\
|DD|____T_\n\
|_ |_____|<\n\
  @-@-@-oo";
    printf("%s\n", train);
}

void flag(){
    FILE *fptr;
    char flag[34];
    fptr = fopen("flag.txt", "r"); 
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    }
    if( fgets (flag, 34, fptr)!=NULL ) {
      puts(flag);
   }
}

int main() {
    setup();
    pretty_train();

    char ticketNo[8];
    char ticketType[16] = "silverTicket!!!";

    printf("Plese input your ticket number: ");
    gets(ticketNo);

    if (strcmp(ticketType, "goldenTicket!!!") == 0) {
        flag();
    } else {
        printf("You need a golden ticket to get the flag!\n");
    }

    return 0;

}