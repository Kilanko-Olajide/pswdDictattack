#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>


void usage(char *program_name) {
    printf("Usage: %s <password to hash> <salt value>\n", program_name);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        usage(argv[0]);
    }

    printf("The password is %s and the salt is %s\n", argv[1], argv[2]);
    printf("Everything hashes to => %s\n", crypt(argv[1], argv[2]));
}
