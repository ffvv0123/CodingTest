'''
가로 두칸, 세로 n칸
사자들이 살아요. 가로 세로로 안 붙게 배치

2*N 배열에 사자를 배치하는 경우의 수 찾기
0마리도 경우의 수

경우의 수 % 9901 출력

dp = 3 7 17 41 

dp[n] = dp[n-2] + 2dp[n-1]

n = 1
-> XX OX XO -> 3 -> 1 + 2

n = 2
-> XX OX XO XX XX OX XO
-> XX XX XX OX XO XO OX -> 7 = 1 + 4 + 2

n = 3
-> XX | OX XO XX XX XX XX | OX XO XX XX OX OX XO XO |  OX XO
-> XX | XX XX OX XO XX XX | XO OX OX XO XX XX XX XX |  XO OX
-> XX | XX Xx XX XX OX XO | XX XX XO OX OX XO OX XO |  OX XO -> 1 + 6 + 8 + 2 = 17

'''

n = int(input())

dp = [0] * (n+1)
dp[1] = 3

if n >= 2:
    dp[2] = 7
    
if n >= 3:
    for i in range(3, n+1):
        dp[i] = (dp[i-2] + 2 * dp[i-1]) % 9901

print(dp[-1])