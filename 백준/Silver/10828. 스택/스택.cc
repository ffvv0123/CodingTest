#include <stdio.h>
#include <string.h>
#define stack_size 10000

int count = -1;
int stack[stack_size];

void push(int x)
{
	count++;
	stack[count] = x;
}

int empty()
{
	if (count == -1)
		return 1;
	else
		return 0;
}

int pop()
{
	if (empty())
	{
		return -1;
	}
	else
	{
		return stack[count--];
	}
}

int top()
{
	if (empty())
		return -1;
	else
		return stack[count];

}

int main()
{
	int n = 0;
	int push_data = 0;
	char command[5] = { 0, }; //처음에 배열을 초기화하는 방법을 몰라서 시간을 많이 썼지만 검색 후 배열을 초기화하는 방법을 참고하고 공부한 뒤 사용하게 되었음

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", command);
		if (!strcmp(command, "push")) //strcmp 함수 또한 기억 속에 잊혀져있었다가 명령어를 인식할 함수가 필요했기에 c언어 책에서 확인 후 사용하게 됨
		{
			scanf("%d", &push_data);
			push(push_data);
		}
		else if (!strcmp(command, "pop"))
		{
			printf("%d\n", pop());
		}
		else if (!strcmp(command, "empty"))
		{
			printf("%d\n", empty());
		}
		else if (!strcmp(command, "size"))
		{
			printf("%d\n", count + 1);
		}
		else if (!strcmp(command, "top"))
		{
			printf("%d\n", top());
		}
	}
	return 0;
}
// 코드 후기 : 참고용으로 나와있었던 stack 함수들의 개념 사이트에 들어가서 코드를 활용해보려 했지만 이해하는 데 어려움이 있어 stack 알고리즘을 활용하는 다른 코드들을 공부 후 
// 사용하게 되었음. 점점 저학년 때 공부했었던 코딩 기억들이 되살아나는 것 같은 기분이 들었음. 하지만 아직 혼자 100% 코딩을 직접 짜려면 시간이 더 걸릴 것으로 보여 이번 스터디를
// 통해 코딩에 익숙해질 수 있으면 좋겠다