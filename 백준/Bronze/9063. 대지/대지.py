import sys

N = int(input())

min_x, min_y, max_x, max_y = 10001, 10001, -10001, -10001

for _ in range(N):
    x, y = map(int, sys.stdin.readline().split())

    if x < min_x:
        min_x = x
    if x > max_x:
        max_x = x
    
    if y < min_y:
        min_y = y
    if y > max_y:
        max_y = y
    
print((max_x - min_x) * (max_y - min_y))