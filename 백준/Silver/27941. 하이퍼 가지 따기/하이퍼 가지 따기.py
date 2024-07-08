import sys

trial = [[0] * 11 for _ in range(2047)]

for i in range(2047):
    trial[i] = list(map(int, sys.stdin.readline().split()))

transpose_trial = list(map(list, zip(*trial)))

for i in range(11):
    x1, x2 = set(transpose_trial[i])
    if transpose_trial[i].count(x1) < transpose_trial[i].count(x2):
        print(x1, end = ' ')
    else:
        print(x2, end = ' ')