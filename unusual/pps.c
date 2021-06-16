#include <stdio.h>

// this paste a token from two other tokens
#define paste(front, back) front ## back

int main() {

    int xy = 1;
    int x = 2;
    int y = 3;

    printf("%d, %d\n", x, y);
    printf("%d\n", paste(x, y));

    return 0;
}