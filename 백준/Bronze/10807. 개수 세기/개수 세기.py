import sys

N = int(input())
num_list = list(map(int, sys.stdin.readline().split()))
v = int(input())

ans = 0
for num in num_list:
    if num == v:
        ans += 1

print(ans)