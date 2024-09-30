import sys

N = int(input())
for _ in range(N):
    pw = input().strip()
    if len(pw) >= 6 and len(pw) <= 9:
        print("yes")
    else:
        print("no")