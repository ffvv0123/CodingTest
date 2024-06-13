'''
a = 10 20 10 30 20 50
-> 10 20 30 50 -> 4

수열 중에서 증가하는 것을 찾아내는 것

어케해볼까? i번째 index까지의 부분수열의 최댓값을 dp로 놓자
초기에는 [1 1 1 1 1 1] -> TC: n=6임. 그러면 그러면 첨에는 1인데

for문 돌려서 이전것보다 현재가 크다면, 가장 큰 수 중 1 올리기

10 < 20
-> 1 2 1 1 1 1

20 < 10 cut
1 2 1 1 1 1

20 < 30 ok
1 2 1 3 1 1

30 < 20 cut
1 2 1 3 1 1
30 < 50 ok
1 2 1 3 1 4
'''
import sys
n = int(input())
A = list(map(int, sys.stdin.readline().split()))

dp = [1] * n

for i in range(1, n):
    for j in range(i):
        if A[j] < A[i]:
            dp[i] = max(dp[i], dp[j] + 1)
    

print(max(dp))