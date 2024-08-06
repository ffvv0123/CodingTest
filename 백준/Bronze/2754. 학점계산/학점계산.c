#include <stdio.h>

char grade[2];
double score = 0.0;

int main() {
    scanf("%s", grade);

    if(grade[0] == 'A') score += 4.0;
    else if(grade[0] == 'B') score += 3.0;
    else if(grade[0] == 'C') score += 2.0;
    else if(grade[0] == 'D') score += 1.0;

    if(grade[1] == '+') score += 0.3;
    else if(grade[1] == '-') score -= 0.3;

    printf("%.1lf\n", score);

    return 0;
}