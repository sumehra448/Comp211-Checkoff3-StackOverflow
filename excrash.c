// Program will crash
//INSTRUCTION TO RUN PROGRAM:
//Normally, protections are turned on by default (such as stack canaries, etc..), which can stop the overflow before we see it. To turn them OFF, type this when compiling
//gcc -fno-stack-protector -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0 -o name filename
//To turn canaries ON, use this
//gcc -fstack-protector-all -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=0 -o name filename
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
