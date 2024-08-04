import sys

N, M = map(int, sys.stdin.readline().split())

basket = [0 for _ in range(N)]

for _ in range(M):
    i, j, k = map(int, sys.stdin.readline().split())
    
    for tmp in range(i-1, j):
        basket[tmp] = k

for b in basket:
    print(b, end=' ')