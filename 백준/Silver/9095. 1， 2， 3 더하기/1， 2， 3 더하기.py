'''
1 -> 1
2 -> 1 + 1 = 2
3 -> 1 + 1 + 1 = 1 + 2 = 2 + 1 = 3

dp[0] = 1
dp[1] = 1
dp[2] = 2
dp[3] = 4
dp[4] = 7
dp[5] = 13
dp[6] = 24
dp[7] = 44

dp[x] = dp[x-1] + dp[x-2] + dp[x-3]

'''

import sys

def count_123(x):
    if x < 3:
        return x
    
    dp = [0] * (x+1)
    dp[0], dp[1], dp[2] = 1, 1, 2

    for i in range(3, x+1):
        dp[i] = dp[i-3] + dp[i-2] + dp[i-1]

    return dp[x]

T = int(sys.stdin.readline().strip())

for _ in range(T):
    x = int(sys.stdin.readline().strip())
    print(count_123(x))
