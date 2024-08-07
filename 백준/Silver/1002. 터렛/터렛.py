import sys

def distance(x1, x2, y1, y2):
    return ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5

T = int(input())

for _ in range(T):
    x1, y1, r1, x2, y2, r2 = map(int, sys.stdin.readline().split())
    d = distance(x1, x2, y1, y2)

    if d == 0 and r1 == r2:
        print(-1)
    elif abs(r1 - r2) == d or r1 + r2 == d:
        print(1)
    elif abs(r1 - r2) < d and d < r1 + r2:
        print(2)
    else:
        print(0)