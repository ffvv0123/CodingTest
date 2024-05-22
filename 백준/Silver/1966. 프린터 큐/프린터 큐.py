'''
큐 -> 중요도
-> 현재 문서보다 중요도 높은게 존재 -> 뒤로 재배치
-> 그게 아니면 인쇄
-> ABCD의 중요도가 2143

N: 문서의 개수, M: 찾을 문서의 인덱스

'''
import sys
from collections import deque
T = int(input())

while(T):
    T -= 1
    N, M = map(int, sys.stdin.readline().split())
    priority = list(map(int, sys.stdin.readline().split()))

    prior_list = sorted(priority)
    trial = 1

    priority = deque(enumerate(priority))

    while(prior_list):
        if priority[0][0] == M and priority[0][1] == prior_list[-1]:
            print(trial)
            break
        elif priority[0][1] == prior_list[-1]:
            prior_list.pop()
            priority.popleft()
            trial += 1
        else:
            tmp = priority[0]
            priority.popleft()
            priority.append(tmp)