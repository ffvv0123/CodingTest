'''
nCk = n-1Ck + n-1Ck-1
'''

N, K = map(int, input().split())

dp = [[0] * (N+1) for _ in range(N+1)]
dp[0][0] = 0
dp[1][0], dp[1][1] = 1, 1

for n in range(2, N+1):
    for k in range(n+1):
        dp[n][k] = dp[n-1][k] + dp[n-1][k-1]

print(dp[N][K] % 10007)