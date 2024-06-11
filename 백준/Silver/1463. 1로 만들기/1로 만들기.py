'''
정수 X -> 연산
X 3나떨 -> 3나누기
X 2나떨 -> 2나누기
1 빼기

-> 1 만들기

dp[1] = 0
dp[2] = 1
dp[3] = 1
dp[4] = 2
dp[5] = 3
dp[6] = 2
dp[7] = 3
dp[8] = 3
dp[9] = 2
dp[10]= 3 -1 /3 /3

4 - 1 = 3 -> 1 + dp[3]
4 / 2 = 2 -> 1 + dp[2]
4 / 3 = X

'''

X = int(input())

dp = [0] * (X+1)

dp[1] = 0
if X >= 2:
    dp[2] = 1
if X >= 3:
    dp[3] = 1

if X >= 4:
    for i in range(4, X+1):
        tmp_div2, tmp_div3 = False, False

        if i % 2 == 0:
            tmp_div2 = True
        if i % 3 == 0:
            tmp_div3 = True

        #dp[i] = min(dp[i-1], dp[i//2], dp[i//3]) + 1

        if tmp_div2 is True and tmp_div3 is True:
            dp[i] = min(dp[i-1], dp[i//2], dp[i//3]) + 1
        elif tmp_div2 is True and tmp_div3 is False:
            dp[i] = min(dp[i-1], dp[i//2]) + 1
        elif tmp_div2 is False and tmp_div3 is True:
            dp[i] = min(dp[i-1], dp[i//3]) + 1
        else:
            dp[i] = dp[i-1] + 1

print(dp[-1])