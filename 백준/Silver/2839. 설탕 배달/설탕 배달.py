N = int(input())
answer = 0

while (N % 5 != 0):
    if N >= 3:
        N -= 3
        answer += 1
    else:
        answer = -1
        break

if answer == -1:
    print(answer)
else:
    answer += N // 5
    print(answer)