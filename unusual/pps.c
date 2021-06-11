#include <stdio.h>

#define paste(front, back) front ## back

int main() {

    int xy = 1;

    printf("%d", paste(x, y));

    return 0;
}