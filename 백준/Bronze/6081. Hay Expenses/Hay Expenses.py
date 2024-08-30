import sys

N, Q = map(int, sys.stdin.readline().split())
dp = []

for i in range(N):
    tmp = int(sys.stdin.readline().strip())
    if len(dp) == 0:
        dp.append(tmp)
    else:
        dp.append(tmp + dp[i-1])

for _ in range(Q):
    s, e = map(int, sys.stdin.readline().split())
    if s == 1:
        print(dp[e-1])
    else:
        print(dp[e-1] - dp[s-2])