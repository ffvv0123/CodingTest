'''
실험대에는 N개의 칸이 있고 각 칸에는 에너지 상수가 주어짐
여기에 막대 자석 설치함. 2 <= 자석의 크기 <= N
-> NS극은 정확한 칸 위에 놓여야 함

1. N극 칸의 에너지 상수만큼 에너지 충전
2. S극 칸의 에너지 상수만큼 에너지 소모
3. abs(N-S) * K 만큼 에너지 소모 [자석의 길이 * K]

-> 주어진 환경에서 변화하는 에너지의 최댓값 [음수 가능]

N: 실험대의 칸 수, K: 상수

1 - 3을 구한다고 하자.
-> N(1) - S(3) - (3-1)K

1 - 2
-> N(1) - S(2) - (2-1)K

2 - 3
-> N(2) - S(3) - (3-2)K
-> F(1,3) = F(1,2) + F(2,3)

-> F(a,c) = F(a,b) + F(b,c)
-> 자석의 길이는 고려하지 않고 2로 생각하면 됨.

'''

import sys

N, K = map(int, sys.stdin.readline().split())
energy = list(map(int, sys.stdin.readline().split()))

NS_list = []
SN_list = []

for i in range(1, N):
    NS_list.append(energy[i-1] - energy[i] - K)
    SN_list.append(energy[i] - energy[i-1] - K)

NS_sum = [0] * (N - 1)
SN_sum = [0] * (N - 1)

NS_sum[0] = NS_list[0]
SN_sum[0] = SN_list[0]

for i in range(1, N - 1):
    NS_sum[i] = max(0, NS_sum[i-1]) + NS_list[i]
    SN_sum[i] = max(0, SN_sum[i-1]) + SN_list[i]

print(max(max(NS_sum), max(SN_sum)))