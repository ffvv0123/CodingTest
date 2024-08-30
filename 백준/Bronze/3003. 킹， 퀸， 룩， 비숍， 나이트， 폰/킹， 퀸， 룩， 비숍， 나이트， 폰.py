chess = list(map(int, input().split()))
answer = [1, 1, 2, 2, 2, 8]

for i, j in zip(chess, answer):
    print(j - i, end = " ")