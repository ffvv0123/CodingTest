import sys
N, r, c = map(int, sys.stdin.readline().split())
count = 0

def Z(N, x, y):
    global count

    if N == 1:
        if x == r and y == c:
            print(count)
            return True
        elif x == r and y + 1 == c:
            print(count+1)
            return True
        elif x + 1 == r and y == c:
            print(count+2)
            return True
        elif x + 1 == r and y + 1 == c:
            print(count+3)
            return True
        count += 4   

    else:
        half = 2**(N-1)
        if r < x + half and c < y + half:
            return Z(N-1, x, y)

        elif r < x + half and c >= y + half:
            count += half**2
            return Z(N-1, x, y + half)

        elif r >= x + half and c < y + half:
            count += half**2 * 2
            return Z(N-1, x + half, y)

        else:
            count += half**2 * 3
            return Z(N-1, x + half, y + half)

Z(N, 0, 0)