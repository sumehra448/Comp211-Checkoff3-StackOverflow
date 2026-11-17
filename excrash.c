// Program will crash
#include <stdio.h>
#include <string.h>

void greet(const char* name) {
    char buffer[16];       // fixed-size buffer on the stack
    strcpy(buffer, name);  // no length check: the bug
    printf("Hello, %s!\n", buffer);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }
    greet(argv[1]);
    printf("Returned safely.\n");
    return 0;
}