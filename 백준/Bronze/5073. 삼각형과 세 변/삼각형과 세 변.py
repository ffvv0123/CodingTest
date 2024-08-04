import sys

while(True):
    A, B, C = map(int, sys.stdin.readline().split())
    if A == B == C == 0:
        break

    max_length = max(max(A, B), max(B, C))

    if max_length >= A + B + C - max_length:
        print('Invalid')
    elif A == B == C:
        print('Equilateral')
    elif A == B or B == C or C == A:
        print('Isosceles')
    else:
        print('Scalene')