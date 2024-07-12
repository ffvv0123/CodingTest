import sys

def md(m, x):
    return (x % m + m) % m

N, Q = map(int, sys.stdin.readline().split())

status = [[0, 0], [0, 1], [1, 0], [1, 1]]
swap_history = []

for _ in range(Q):
    command = sys.stdin.readline().split()
    
    if command[0] == 'RO':
        for i in range(4):
            if status[i][0] % 2 == 0:
                status[i][1] = (status[i][1] + 1) % N
    elif command[0] == 'RE':
        for i in range(4):
            if status[i][0] % 2 == 1:
                status[i][1] = (status[i][1] + 1) % N
    elif command[0] == 'CO':
        for i in range(4):
            if status[i][1] % 2 == 0:
                status[i][0] = (status[i][0] + 1) % N
    elif command[0] == 'CE':
        for i in range(4):
            if status[i][1] % 2 == 1:
                status[i][0] = (status[i][0] + 1) % N
    elif command[0] == 'S':
        r1, c1, r2, c2 = map(int, command[1:])
        r1 -= 1
        c1 -= 1
        r2 -= 1
        c2 -= 1

        i_first, i_second = -1, -1
        for i in range(4):
            if abs(r1 - status[i][0]) % 2 == 0 and abs(c1 - status[i][1]) % 2 == 0:
                i_first = i
            if abs(r2 - status[i][0]) % 2 == 0 and abs(c2 - status[i][1]) % 2 == 0:
                i_second = i

        swap_history.append([i_first, r1 - status[i_first][0], c1 - status[i_first][1], i_second, r2 - status[i_second][0], c2 - status[i_second][1]])

ans = [[0] * N for _ in range(N)]

for i in range(4):
    num = 1 if i == 0 else 2 if i == 1 else N + 1 if i == 2 else N + 2
    y = status[i][0]
    for c in range(N // 2):
        x = status[i][1]
        for c2 in range(N // 2):
            ans[y][x] = num
            x = (x + 2) % N
            num += 2
        y = (y + 2) % N
        num += N

for i1, dy1, dx1, i2, dy2, dx2 in swap_history:
    y1 = md(N, status[i1][0] + dy1)
    x1 = md(N, status[i1][1] + dx1)
    y2 = md(N, status[i2][0] + dy2)
    x2 = md(N, status[i2][1] + dx2)
    
    ans[y1][x1], ans[y2][x2] = ans[y2][x2], ans[y1][x1]

for row in ans:
    print(' '.join(map(str, row)))