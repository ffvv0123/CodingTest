def promising(x):
    for i in range(x):
        if chess[x] == chess[i] or abs(chess[x] - chess[i]) == abs(x - i):
            return False
    return True

def Nqueen(x):
    global answer
    if x == N:
        answer += 1

    else:
        for i in range(N):
            chess[x] = i
            if promising(x):
                Nqueen(x + 1)

N = int(input())
answer = 0
chess = [0] * N
                
Nqueen(0)
print(answer)