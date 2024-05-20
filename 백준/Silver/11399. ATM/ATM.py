import sys
N = int(input())
queue = list(map(int, sys.stdin.readline().split()))

queue.sort()
answer = 0

for i in range(len(queue)):
    answer += sum(queue[:i+1])

print(answer)