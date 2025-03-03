import sys

ans_string = sys.stdin.readline().strip()
N = int(input())
ans = 0

for _ in range(N):
    data = sys.stdin.readline().strip()
    data += data
    if ans_string in data:
        ans += 1

print(ans)