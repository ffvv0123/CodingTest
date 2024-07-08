N = int(input())

if N == 1:
    pass
else:
    idx = 2
    while(N != 1):
        if N % idx == 0:
            N //= idx
            print(idx)
        if N % idx != 0:
            idx += 1
