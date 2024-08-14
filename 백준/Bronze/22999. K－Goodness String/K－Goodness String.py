T = int(input())

for i in range(T):
    N, K = map(int, input().split(' '))
    S = input()
    score = 0

    for j in range(N//2):
        if S[j] != S[N-1-j]:
            score += 1
    x = i+1
    y = abs(score - K)

    print(f'Case #{x}: {y}')
