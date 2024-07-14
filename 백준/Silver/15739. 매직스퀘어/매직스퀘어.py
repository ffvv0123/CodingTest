import sys

def is_square(matrix, N):
    checklist = [0] * (N**2 + 1)

    for i in range(N):
        for j in range(N):
            checklist[matrix[i][j]] = 1
    
    for i in range(N**2):
        if checklist[i+1] != 1:
            return False
    return True

    

def is_correct_sum(matrix, N):
    checker = N * (N**2 + 1) // 2
    
    for i in range(N):
        sum = 0
        for j in range(N):
            sum += matrix[i][j]
        if sum != checker:
            return False
        
        sum = 0
        for j in range(N):
            sum += matrix[j][i]
        if sum != checker:
            return False
        
    sum = 0
    for i in range(N):
        sum += matrix[i][i]
    if sum != checker:
        return False
    
    sum = 0
    for i in range(N):
        sum += matrix[N-1-i][i]
    if sum != checker:
        return False
    
    return True

N = int(input())
matrix = []
for _ in range(N):
    matrix.append(list(map(int, sys.stdin.readline().split())))

if is_square(matrix, N) and is_correct_sum(matrix, N):
    print("TRUE")
else:
    print("FALSE")