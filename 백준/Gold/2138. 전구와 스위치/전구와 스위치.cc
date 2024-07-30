#include <iostream>
using namespace std;

int init[100001];
int copy_init[100001];
int target[100001];

int N;

void push(int blubArray[], int switchNum)
{
	for (int i = switchNum - 1; i <= switchNum + 1; i++)
	{
		if (i >= 0 && i < N)
		{
			blubArray[i] = 1 - blubArray[i];
		}
	}
}

bool go(int blubArray[], int targetBlubArray[], int& result)
{
	int ans = 0;

	for (int i = 1; i < N; i++)
	{
		if (blubArray[i-1] != targetBlubArray[i-1])
		{
			push(blubArray, i);
			ans++;
		}
	}
	result = ans;

	for (int i = 0; i < N; i++)
	{
		if (blubArray[i] != targetBlubArray[i])
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	int ans = -1;
	int nowAns = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%1d", &init[i]);
		copy_init[i] = init[i];
	}

	for (int i = 0; i < N; i++) 
		scanf("%1d", &target[i]);


	if (go(init, target, nowAns))
	{
		if (ans == -1) ans = nowAns;
		else ans = min(ans, nowAns);
	}


	push(copy_init, 0);
	nowAns = 1;

	if(go(copy_init, target, nowAns))
	{
		nowAns++;
		if (ans == -1) ans = nowAns;
		else ans = min(ans, nowAns);
	}

	printf("%d\n", ans);

	return 0;
}