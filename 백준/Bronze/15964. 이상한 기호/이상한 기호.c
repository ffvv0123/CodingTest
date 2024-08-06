#include <stdio.h>

long A, B;

long calc(long A, long B) {
    return (A+B) * (A-B);
}

int main() {
    scanf("%ld %ld", &A, &B);
    printf("%ld", calc(A, B));

    return 0;
}