import sys

def my_round(x):
    if x - int(x) >= 0.5:
        return int(x) + 1
    else:
        return int(x)

n = int(sys.stdin.readline())
score = [0] * n

if n > 0:
    for i in range(n):
        score[i] = int(sys.stdin.readline())

    num_cutting_score = my_round(n * 0.15)
    score.sort()

    sum_score = 0
    for i in range(num_cutting_score, n - num_cutting_score):
        sum_score += score[i]

    balanced_score = my_round(sum_score / (n - 2 * num_cutting_score))
else:
    balanced_score = 0

print(balanced_score)
