import sys

counter = []
answer = False

for _ in range(10):
    eggplant = list(map(str, sys.stdin.readline().split()))
    counter.append(eggplant)

for i in range(10):
    checker = counter[i][0]
    for j in range(1, 10):
        if checker != counter[i][j]:
            break
        if j == 9 and checker == counter[i][j]:
            answer = True
    if answer:
        break


if not answer:
    for i in range(10):
        checker = counter[0][i]
        for j in range(1, 10):
            if checker != counter[j][i]:
                break
            if j == 9 and checker == counter[j][i]:
                answer = True
        if answer:
            break

if answer:
    print(1)
else:
    print(0)