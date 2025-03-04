import sys

N, M = map(int, sys.stdin.readline().split())
A_list, B_list = [0], [0]

for _ in range(N):
    dist, time = map(int, sys.stdin.readline().split())
    for _ in range(time):
        A_list.append(A_list[-1] + dist)

for _ in range(M):
    dist, time = map(int, sys.stdin.readline().split())
    for _ in range(time):
        B_list.append(B_list[-1] + dist)

ans = 0
prev = 0

for i in range(1, len(A_list)):
    if A_list[i] > B_list[i]:
        curr = 1
    elif A_list[i] < B_list[i]:
        curr = -1
    else:
        curr = 0
    
    if curr != 0:
        if prev != 0 and curr != prev:
            ans += 1
        prev = curr

print(ans)