#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DEBUG 0

void playAnimation(void) {
    char banner[] = {0x7c,0x2d,0x7c,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x20,0x20,0x5f,0x5f,0x5f,0x5f,0x5f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x5f,0x20,0x20,0x5f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x5f,0x5f,0x5f,0x5f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x20,0x2f,0x20,0x20,0x5f,0x5f,0x5f,0x7c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x20,0x5f,0x7c,0x7c,0x20,0x7c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x7c,0x5f,0x20,0x20,0x20,0x5f,0x7c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x20,0x5c,0x20,0x60,0x2d,0x2d,0x2e,0x20,0x20,0x20,0x5f,0x5f,0x5f,0x20,0x20,0x7c,0x20,0x7c,0x5f,0x20,0x7c,0x20,0x7c,0x5f,0x20,0x5f,0x5f,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x5f,0x20,0x20,0x5f,0x5f,0x20,0x5f,0x20,0x20,0x5f,0x20,0x5f,0x5f,0x20,0x20,0x20,0x5f,0x5f,0x5f,0x20,0x20,0x20,0x20,0x7c,0x20,0x7c,0x20,0x20,0x20,0x5f,0x20,0x5f,0x5f,0x20,0x20,0x20,0x5f,0x5f,0x20,0x5f,0x20,0x20,0x20,0x5f,0x5f,0x5f,0x20,0x20,0x20,0x5f,0x5f,0x5f,0x20,0x20,0x5f,0x20,0x5f,0x5f,0x20,0x20,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x20,0x20,0x60,0x2d,0x2d,0x2e,0x20,0x5c,0x20,0x2f,0x20,0x5f,0x20,0x5c,0x20,0x7c,0x20,0x20,0x5f,0x7c,0x7c,0x20,0x5f,0x5f,0x7c,0x5c,0x20,0x5c,0x20,0x2f,0x5c,0x20,0x2f,0x20,0x2f,0x20,0x2f,0x20,0x5f,0x60,0x20,0x7c,0x7c,0x20,0x27,0x5f,0x5f,0x7c,0x20,0x2f,0x20,0x5f,0x20,0x5c,0x20,0x20,0x20,0x7c,0x20,0x7c,0x20,0x20,0x7c,0x20,0x27,0x5f,0x5f,0x7c,0x20,0x2f,0x20,0x5f,0x60,0x20,0x7c,0x20,0x2f,0x20,0x5f,0x5f,0x7c,0x20,0x2f,0x20,0x5f,0x20,0x5c,0x7c,0x20,0x27,0x5f,0x5f,0x7c,0x20,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x20,0x2f,0x5c,0x5f,0x5f,0x2f,0x20,0x2f,0x7c,0x20,0x28,0x5f,0x29,0x20,0x7c,0x7c,0x20,0x7c,0x20,0x20,0x7c,0x20,0x7c,0x5f,0x20,0x20,0x5c,0x20,0x56,0x20,0x20,0x56,0x20,0x2f,0x20,0x7c,0x20,0x28,0x5f,0x7c,0x20,0x7c,0x7c,0x20,0x7c,0x20,0x20,0x20,0x7c,0x20,0x20,0x5f,0x5f,0x2f,0x20,0x20,0x20,0x7c,0x20,0x7c,0x20,0x20,0x7c,0x20,0x7c,0x20,0x20,0x20,0x7c,0x20,0x28,0x5f,0x7c,0x20,0x7c,0x7c,0x20,0x28,0x5f,0x5f,0x20,0x7c,0x20,0x20,0x5f,0x5f,0x2f,0x7c,0x20,0x7c,0x20,0x20,0x20,0x20,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x20,0x5c,0x5f,0x5f,0x5f,0x5f,0x2f,0x20,0x20,0x5c,0x5f,0x5f,0x5f,0x2f,0x20,0x7c,0x5f,0x7c,0x20,0x20,0x20,0x5c,0x5f,0x5f,0x7c,0x20,0x20,0x5c,0x5f,0x2f,0x5c,0x5f,0x2f,0x20,0x20,0x20,0x5c,0x5f,0x5f,0x2c,0x5f,0x7c,0x7c,0x5f,0x7c,0x20,0x20,0x20,0x20,0x5c,0x5f,0x5f,0x5f,0x7c,0x20,0x20,0x20,0x5c,0x5f,0x2f,0x20,0x20,0x7c,0x5f,0x7c,0x20,0x20,0x20,0x20,0x5c,0x5f,0x5f,0x2c,0x5f,0x7c,0x20,0x5c,0x5f,0x5f,0x5f,0x7c,0x20,0x5c,0x5f,0x5f,0x5f,0x7c,0x7c,0x5f,0x7c,0x20,0x20,0x20,0x20,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x7c,0x2d,0x7c,0x0a,0x7c,0x2d,0x7c,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x2d,0x7c,0x2d,0x7c, 0x00};
    char frame1[] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x20,0x20,0x20,0x20,0x2c,0x27,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x20,0x20,0x20,0x2f,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x5f,0x5f,0x5f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x5f,0x5f,0x5b,0x20,0x2c,0x27,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x20,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x5f,0x5f,0x20,0x20,0x20,0x20,0x20,0x5f,0x5f,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x5d,0x5c,0x20,0x5f,0x20,0x2f,0x5b,0x20,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x5d,0x20,0x28,0x23,0x29,0x20,0x5b,0x20,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x3a,0x3d,0x3d,0x3d,0x3d,0x27,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x5f,0x5d,0x2e,0x6e,0x48,0x6e,0x2e,0x5b,0x5f,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x48,0x48,0x48,0x48,0x48,0x2e,0x20,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x2f,0x20,0x20,0x20,0x60,0x48,0x48,0x28,0x22,0x4e,0x20,0x20,0x5c,0x20,0x5b,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x5f,0x5f,0x5d,0x2f,0x20,0x20,0x20,0x20,0x20,0x48,0x48,0x48,0x20,0x20,0x22,0x20,0x20,0x5c,0x5b,0x5f,0x5f,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x4e,0x4e,0x4e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x4e,0x2f,0x22,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x4e,0x20,0x48,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x4e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x71,0x2c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x0a, 0x00};
    char frame2[] = {0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x20,0x20,0x20,0x20,0x2c,0x27,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x20,0x20,0x20,0x2f,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x5f,0x5f,0x5f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5f,0x5f,0x5f,0x5b,0x20,0x2c,0x27,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x5c,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x20,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x5f,0x5f,0x20,0x20,0x20,0x20,0x20,0x5f,0x5f,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x5d,0x5c,0x20,0x5f,0x20,0x2f,0x5b,0x20,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x7c,0x3a,0x20,0x20,0x20,0x7c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x5d,0x20,0x28,0x23,0x29,0x20,0x5b,0x20,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x20,0x3a,0x3d,0x3d,0x3d,0x3d,0x27,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x5f,0x5d,0x2e,0x6e,0x48,0x6e,0x2e,0x5b,0x5f,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x20,0x48,0x48,0x48,0x48,0x48,0x2e,0x20,0x5b,0x20,0x20,0x5b,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x5d,0x20,0x2f,0x20,0x20,0x4e,0x22,0x29,0x48,0x48,0x60,0x20,0x20,0x20,0x5c,0x20,0x5b,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x5f,0x5f,0x5d,0x2f,0x20,0x20,0x22,0x20,0x20,0x48,0x48,0x48,0x20,0x20,0x20,0x20,0x20,0x5c,0x5b,0x5f,0x5f,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x4e,0x4e,0x4e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x22,0x2f,0x4e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5d,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x48,0x20,0x4e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5b,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x4e,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2c,0x71,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x2f,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x5c,0x0a, 0x00};

    for (int i = 0; i < 5; i++) {
        printf("\033[2J\033[H");
        puts(banner);
        puts(frame1);
        usleep(300000);
        printf("\033[2J\033[H");
        puts(banner);
        puts(frame2);
        usleep(300000);
    }

}

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

int aes_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
                unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    /* Create and initialize the context */
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    /*
     * Initialize the decryption operation.
     * Use 256 bit AES (i.e. a 256 bit key length).
     */
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    /*
     * Provide the message to be decrypted, and obtain the plaintext output.
     * EVP_DecryptUpdate can be called multiple times if necessary.
     */
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    /*
     * Finalize the decryption. Further plaintext bytes may be written at this stage.
     */
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <flag>\n", argv[0]);
        exit(1);
    }

    playAnimation();

    // Example usage
    unsigned char *key = (unsigned char *)"f669d2db7c66678ad27862299a4aea78"; // 32 bytes key for AES-256
    unsigned char *iv = (unsigned char *)"b9bc94e32aa014f9"; // 16 bytes IV for AES-256-CBC

    /* https://gchq.github.io/CyberChef/#recipe=AES_Encrypt(%7B'option':'Latin1','string':'f669d2db7c66678ad27862299a4aea78'%7D,%7B'option':'Latin1','string':'b9bc94e32aa014f9'%7D,'CBC','Raw','Raw',%7B'option':'Hex','string':''%7D)To_Hex('0x%20with%20comma',0)&input=R1RCUXtsdHI0YzNfdW52MzFsNV90aDNfaDFkZDNuX3c0eTVfMW5fdGgzXzUwZnR3NHIzX200ejMhIX0&oeol=NEL */
    /* GTBQ{ltr4c3_unv31l5_th3_h1dd3n_w4y5_1n_th3_50ftw4r3_m4z3!!} */
    unsigned char ct[] = {0xcc,0x81,0x3a,0xc2,0xb5,0x31,0xb7,0xf1,0x23,0xf0,0xed,0x6b,0xc3,0x11,0xe1,0xd1,0x76,0x4b,0x34,0x51,0x08,0x7b,0x15,0xa1,0x00,0xf3,0x2e,0xc5,0xca,0x9e,0xab,0x49,0xd8,0x54,0x2b,0xee,0x43,0x8b,0x50,0xad,0x75,0x1c,0x14,0xcb,0x64,0xe8,0x13,0xed,0x79,0xf6,0x26,0xb3,0xa7,0x0e,0x20,0x78,0xaf,0x78,0x28,0x9a,0x4b,0xa6,0x42,0xf4};
    int ciphertext_len = sizeof(ct);

    unsigned char pt[128];

    int pt_len = aes_decrypt(ct, sizeof(ct), key, iv, pt);
    pt[pt_len] = '\0';

    int input_len = strlen(argv[1]);
    if (pt_len != input_len) {
        char debugString[0x100];
        sprintf(debugString, "DEBUG: Invalid Input Length. %d provided, %d expected.", input_len, pt_len);

        if (DEBUG) {
            puts(debugString);
        }

        puts("That's not the flag! It's not even the right length!");
        exit(1);
    }

    if (!strncmp(pt, argv[1], pt_len)) {
        puts("Wow! You found the flag!? How!?");
    } else {
        puts("Wrong");
    }

    return 1;
}
