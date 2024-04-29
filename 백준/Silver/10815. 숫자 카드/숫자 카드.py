import sys

N = int(sys.stdin.readline())
cards = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())
checks = list(map(int, sys.stdin.readline().split()))

dic = {}

for i in checks:
    dic[i] = 0

for i in cards:
    if i in dic:
        dic[i] = 1

for i in dic:
    print(dic[i], end=' ')