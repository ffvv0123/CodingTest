import sys

N = int(sys.stdin.readline())
radix_list = [0] * (10001)

for i in range(N):
    tmp = int(sys.stdin.readline())
    radix_list[tmp] += 1

for i in range(10001):
    if radix_list[i] == 0:
        continue
    for j in range(radix_list[i]):
        print(i)