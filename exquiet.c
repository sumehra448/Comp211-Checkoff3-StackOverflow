// Program will run quietly
//To run program, use instructions for excrash.c
#include <stdio.h>
#include <string.h>

struct User {
    char name[8];  // 8 bytes
    int is_admin;  // 4 bytes, sits right after name in memory
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    struct User user;
    user.is_admin = 0;  // everyone starts as a regular user

    strcpy(user.name, argv[1]);  // bug: no length check

    printf("name = %s, is_admin = %d\n", user.name, user.is_admin);

    if (user.is_admin)
        printf("Access granted: admin panel\n");
    else
        printf("Regular user\n");

    return 0;
}
