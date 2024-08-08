import sys

N, k = map(int, sys.stdin.readline().split())
score = list(map(int, sys.stdin.readline().split()))

score = sorted(score, reverse = True)
print(score[k-1])