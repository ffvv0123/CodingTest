import sys

while(True):
    n = int(sys.stdin.readline().strip())
    if n == -1: break

    factor = set()
    tmp = 0

    for i in range(1, n//2 + 1):
        if n % i == 0:
            factor.add(i)
            factor.add(n // i)
    factor.discard(n)

    if n == sum(factor):
        print(n, '=', ' + '.join(map(str, sorted(factor))))
    else:
        print(n, 'is NOT perfect.')