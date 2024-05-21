import sys

S = sys.stdin.readline().strip()

answer_list = []

for i in range(len(S)):
    for j in range(i + 1):
        answer_list.append(S[j:i+1])

print(len(set(answer_list)))