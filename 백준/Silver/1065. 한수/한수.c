#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>

int sequence(int);

int main()
{
	int num;
	int sum = 0;

	scanf(" %d", &num);

	for (int i = 1; i <= num; i++) {
		sum += sequence(i);
	}
	printf("%d", sum);

	return 0;
}

int sequence(int num)
{
	int count = 0;
	int v_1000, v_100, v_10, v_1;

	v_1000 = num / 1000;
	v_100 = (num % 1000) / 100;
	v_10 = (num % 100) / 10;
	v_1 = num % 10;

	if (v_1000 == 0) {
		if (v_100 == 0) {
			count++;
		}
		else {
			if ((v_100 - v_10 == v_10 - v_1)) {
				count++;
			}
		}
	}

	else {
		if ((v_1000 - v_100 == v_100 - v_10) && (v_100 - v_10 == v_10 - v_1)) {
			count++;
		}
	}
	return count;
}