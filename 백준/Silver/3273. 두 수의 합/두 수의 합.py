import sys
n = int(sys.stdin.readline().strip())
lst = list(map(int, sys.stdin.readline().split()))
x = int(sys.stdin.readline().strip())

start, end = 0, len(lst) - 1
lst.sort()
answer = 0

while(start < end):
    if lst[start] + lst[end] == x:
        answer += 1
        start += 1
        end -= 1
    elif lst[start] + lst[end] > x:
        end -= 1
        #start += 1
    else:
        start += 1
        #end -= 1

print(answer)