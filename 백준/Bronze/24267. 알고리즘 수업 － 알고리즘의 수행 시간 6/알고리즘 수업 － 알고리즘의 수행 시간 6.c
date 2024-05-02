#include <stdio.h>



int main() {
    long n;
    scanf("%ld", &n);

    long ans = n * (n-1) * (n-2) / 6;

    printf("%ld\n%d", ans, 3);

    return 0;
}