#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#define DO_SLEEPS 1

/* GTBQ{w3lc0m3_t0_th3_w0nd3rfu1_w0r1d_0f_d3bugg3r5} */
const char FLAG_ENC[] = "\x14\x67\x21\x23\x48\x03\x78\x5f\x1a\x11\x4c\x12\x0c\x47\x53\x2d\x47\x1c\x78\x6c\x0e\x11\x4f\x45\x60\x41\x05\x07\x02\x2b\x3c\x03\x0b\x10\x45\x7e\x63\x55\x3c\x16\x00\x16\x3e\x54\x1e\x12\x53\x14\x2e";
const char KEY[] = "S3cr3tK3y!!!";

int main () {

    printf("%s\n", "-> Hello, can you pass me the flag?");

#if DO_SLEEPS == 1
    sleep(1);
#endif

    char *addr = mmap((void *) 0x13370000, 0x10000, PROT_READ | PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);

    char message[0x100] = {0};
    snprintf(message, 0x100, "Sure, I'm placing it at address %p. Give me 2 seconds <-", addr);
    printf("%100s\n", message);

#if DO_SLEEPS == 1
    sleep(2);
#endif

    for (int i = 0; i < sizeof(FLAG_ENC); i++) {
        addr[i] = FLAG_ENC[i] ^ KEY[i % (sizeof(KEY) - 1)];
    }
    addr[sizeof(FLAG_ENC) - 1] = '\x00';

    printf("%100s\n", "Ok, it's there now. I'll give you five seconds to pause and get it. <-");

#if DO_SLEEPS == 1
    sleep(5);
#endif

    printf("%100s\n", "I removed it now so noone can snoop in and steel the flag. Hope you had time to get it :) <-");

    return 0;
}
