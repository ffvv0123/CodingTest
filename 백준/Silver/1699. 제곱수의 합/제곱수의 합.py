'''
겁나 생각하기 힘든 문제임.

dp 배열의 의미: 최소한의 제곱수의 합으로 N을 만들 떄, 제곱수의 수가 들어감.

일단 dp배열을 dp[i] = i로 만들어두기

일반화 시켜보면 dp[11] = dp[11 - 9] + dp[9] = dp[2] + dp[9]
-> 가능한 제곱수들 빼면서 다 확인해보기.
-> 내가 생각 못했던 것은 가능한 가장 큰 제곱수만 뺐던 것임.
-> 그 이하의 제곱수까지 계산하면서 최솟값을 갱신했더라면 풀렸음.
'''

N = int(input())

dp = [i for i in range(N+1)]

for i in range(1, N+1):
    for j in range(1, i+1):
        if j**2 > i:
            break
        else:
            dp[i] = min(dp[i], dp[i - j**2] + 1)

print(dp[N])