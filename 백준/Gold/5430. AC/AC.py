import sys
from collections import deque

T = int(input())

for _ in range(T):
    p = sys.stdin.readline().strip()
    n = int(sys.stdin.readline().strip())

    numbers = sys.stdin.readline().strip()
    
    if numbers != '[]':
        numbers = numbers[1:-1]
        dq = deque(numbers.split(','))
    else:
        dq = deque()

    R_count = 0
    is_error = False
    
    for i in range(len(p)):
        if p[i] == 'R':
            R_count += 1
        elif p[i] == 'D':
            if len(dq) == 0:
                is_error = True
                break
            else:
                if R_count % 2 == 0:
                    dq.popleft()
                else:
                    dq.pop()
    if is_error:
        print('error')
    else:
        print('[', end='')
        if R_count % 2 == 0:
            print(",".join(dq), end = "")
        else:
            print(",".join(reversed(dq)), end = "") 
        print(']')
        
