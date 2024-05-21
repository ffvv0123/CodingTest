'''
듣보잡 = 교집합(듣,보)
-> 알파벳순 정렬, 숫자

'''

import sys
N, M = map(int, sys.stdin.readline().split())

non_seed = [''] * N
non_heard = [''] * M

for i in range(N):
    tmp = sys.stdin.readline().strip()
    non_seed[i] = tmp

for i in range(M):
    tmp = sys.stdin.readline().strip()
    non_heard[i] = tmp

answer = list(set.intersection(set(non_seed), set(non_heard)))
answer.sort()

print(len(answer))
for i in answer:
    print(i)