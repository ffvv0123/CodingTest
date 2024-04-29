import sys
chess = list(map(int, sys.stdin.readline().split()))
ans = [1,1,2,2,2,8]

for i, j in zip(chess, ans):
    print(j - i, end=' ')