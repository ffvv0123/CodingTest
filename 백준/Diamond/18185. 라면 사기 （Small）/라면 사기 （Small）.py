import sys

N = int(input())
A = list(map(int, sys.stdin.readline().split())) + [0, 0]
answer = 0

for i in range(N):
    if A[i+2] < A[i+1]:
        min_value = min(A[i], A[i+1] - A[i+2])
        for m in range(2):
            A[i + m] -= min_value
        answer += 5 * min_value
        
        min_value = min(A[i:i+3])
        answer += 7 * min_value
        for m in range(3):
            A[i + m] -= min_value

        answer += 3 * A[i]

    else:
        min_value = min(A[i:i+3])
        answer += 7 * min_value
        for m in range(3):
            A[i + m] -= min_value

        min_value = min(A[i:i+2])
        answer += 5 * min_value
        for m in range(2):
            A[i + m] -= min_value

        answer += 3 * A[i]    
        
print(answer)