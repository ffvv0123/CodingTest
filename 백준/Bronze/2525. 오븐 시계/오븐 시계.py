import sys
A, B = map(int, sys.stdin.readline().split())
C = int(sys.stdin.readline())

C_hour = C // 60
C_min = C % 60

ans_hour = A + C_hour
ans_min = B + C_min

if(ans_min >= 60):
    ans_min -= 60
    ans_hour += 1

ans_hour %= 24

print(ans_hour, ans_min)