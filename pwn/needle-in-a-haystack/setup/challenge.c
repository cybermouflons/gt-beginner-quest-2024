#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void setup(){
    char dots[3] = "...";
    char arr1[46] = "Can you please help me with finding my needle?";
    for(int i = 0; arr1[i] != '\0'; i++){
        printf("%c", arr1[i]);
        fflush(stdout);
        usleep(15000);
    }
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("%c ", dots[i]);
        fflush(stdout);
        usleep(550000);
    }
    printf("\n");
    char arr2[45] = "I really have to sew this button on my shirt.";
    for(int i = 0; arr2[i] != '\0'; i++){
        printf("%c", arr2[i]);
        fflush(stdout);
        usleep(15000);
    }
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("%c ", dots[i]);
        fflush(stdout);
        usleep(550000);
    }
    printf("\n");
    char arr3[84] = "The needle got lost in this haystack. Please stop by the haystack and search for it.";
    for(int i = 0; arr3[i] != '\0'; i++){
        printf("%c", arr3[i]);
        fflush(stdout);
        usleep(15000);
    }
    printf("\n");
    for(int i = 0; i < 3; i++){
        printf("%c ", dots[i]);
        fflush(stdout);
        usleep(550000);
    }
    printf("\n");
}

void haystack(){
    __asm__ (
        "movabs $0xdeadbeefdeadbeef, %r12;"
        "movl $0x20657241, 24(%rsp);"
        "movl $0x20756f79, 28(%rsp);"
        "movl $0x6b6f6f6c, 32(%rsp);"
        "movl $0x20676e69, 36(%rsp);"
        "movl $0x20726f66, 40(%rsp);"
        "movl $0x656e2061, 44(%rsp);"
        "movl $0x656c6465, 48(%rsp);"
        "movl $0x0000003f, 52(%rsp);"
        "nop;nop;nop;"
        "movl $0,112(%rsp);movl $0,116(%rsp);movabs $0xbcc9d9948fefeaa8, %r11;mov %r11, 112(%rsp);xor %r12,112(%rsp);"
        "movl $0,120(%rsp);movl $0,124(%rsp);movabs $0xa980cd84bd9dccc2, %r11;mov %r11, 120(%rsp);xor %r12,120(%rsp);"
        "movl $0,128(%rsp);movl $0,132(%rsp);movabs $0xedc38e8bf3c1d2dc, %r11;mov %r11, 128(%rsp);xor %r12,128(%rsp);"
        "movl $0,136(%rsp);movl $0,140(%rsp);movabs $0xb09ccd9af3c38ec2, %r11;mov %r11, 136(%rsp);xor %r12,136(%rsp);"
        "movl $0,144(%rsp);movl $0,148(%rsp);movabs $0xded09f8dbaca9388, %r11;mov %r11, 144(%rsp);xor %r12,144(%rsp);"
        "nop;nop;nop;"
        "movl $0,112(%rsp);movl $0,116(%rsp);"
        "movl $0,120(%rsp);movl $0,124(%rsp);"
        "movl $0,128(%rsp);movl $0,132(%rsp);"
        "movl $0,136(%rsp);movl $0,140(%rsp);"
        "movl $0,144(%rsp);movl $0,148(%rsp);"
    );
    
}

void end(){
    char arr1[47] = "Did you stop by the haystack to find my needle?";
    for(int i = 0; i < 47; i++){
        printf("%c", arr1[i]);
        fflush(stdout);
        usleep(15000);
    }
    printf("\n");
    exit(0);
}

void main() {
    setup();
    haystack();
    end();
}