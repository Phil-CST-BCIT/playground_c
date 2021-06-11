#include <stdio.h>

// this paste a token from two other tokens
#define paste(front, back) front ## back

int main() {

    int xy = 1;

    printf("%d", paste(x, y));

    return 0;
}