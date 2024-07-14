import sys

H = int(input())
W = int(input())

answer = min(H, W)
print(answer * 100 // 2)