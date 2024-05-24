import sys

num_stairs = int(sys.stdin.readline())
stairs = [int(sys.stdin.readline()) for _ in range(num_stairs)]
dp = [0 for _ in range(num_stairs)]

if num_stairs <= 2:
    print(sum(stairs))
else:
    dp[0] = stairs[0]
    dp[1] = stairs[0] + stairs[1]
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2])

    for i in range(3, num_stairs):
        dp[i] = max(dp[i-3] + stairs[i-1] + stairs[i], dp[i-2] + stairs[i])

    print(dp[-1])