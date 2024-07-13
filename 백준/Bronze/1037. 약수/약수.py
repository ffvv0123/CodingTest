import sys

N = int(input())
measure = list(map(int, sys.stdin.readline().split()))
measure.sort()

print(measure[0] * measure[-1])