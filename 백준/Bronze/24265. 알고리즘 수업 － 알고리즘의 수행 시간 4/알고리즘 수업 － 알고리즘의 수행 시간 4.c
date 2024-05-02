#include <stdio.h>

int main() {
    long n;
    scanf("%ld", &n);

    printf("%ld\n%d", n * (n-1) / 2, 2);

    return 0;
}