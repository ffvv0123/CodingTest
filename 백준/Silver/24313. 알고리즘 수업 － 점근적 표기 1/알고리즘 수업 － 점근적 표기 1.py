import sys
a1, a0 = map(int, sys.stdin.readline().split())
c = int(sys.stdin.readline())
n0 = int(sys.stdin.readline())

flag = 0

for n in range(n0, 101):
    if(a1 * n + a0 <= c * n):
        flag = 1
    else:
        flag = 0
        break

print(flag)