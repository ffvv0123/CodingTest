'''
ax + by = c
dx + ey = f
x, y is integer where -999 to 999
'''

import sys
a, b, c, d, e, f = map(int, sys.stdin.readline().split())

for x in range(-999, 1000):
    for y in range(-999, 1000):
        if a*x + b*y == c and d*x + e*y == f:
            print(x, y)
            break