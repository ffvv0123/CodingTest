import sys

length = list(map(int, sys.stdin.readline().split()))
length.sort()

if(length[-1] < length[0] + length[1]):
    print(sum(length))
else:
    print(2 * (length[0] + length[1]) - 1)