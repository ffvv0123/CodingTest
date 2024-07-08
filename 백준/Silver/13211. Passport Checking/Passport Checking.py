import sys

N = int(input())
stolen_passport = dict()

for _ in range(N):
    passport_id = sys.stdin.readline().strip()
    stolen_passport[passport_id] = 1

M = int(input())

answer = 0
for _ in range(M):
    check_passport = sys.stdin.readline().strip()
    if check_passport in stolen_passport:
        answer += 1

print(answer)