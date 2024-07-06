import sys

N = int(sys.stdin.readline())
stat = []

for i in range(N):
    stat.append(int(sys.stdin.readline()))

stat.sort()

avg_sum = 0
for i in stat:
    avg_sum += i

average = avg_sum / len(stat)
if average - avg_sum // len(stat) >= 0.5:
    average = avg_sum // len(stat) + 1
else:
    average = avg_sum // len(stat)


print(average)
print(stat[N // 2])

dic = dict()
for i in stat:
    if i in dic:
        dic[i] += 1
    else:
        dic[i] = 1

cnt = max(dic.values())
mode_list = []

for i in dic:
    if dic[i] == cnt:
        mode_list.append(i)

print(mode_list[0]) if len(mode_list) == 1 else print(mode_list[1])

print(stat[-1] - stat[0])