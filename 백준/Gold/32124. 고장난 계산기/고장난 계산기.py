import sys

N, P = map(int, sys.stdin.readline().split())
expr = sys.stdin.readline().strip()

expr = '(' + expr.replace('(', '((').replace(')', '))').replace('+', ')+(') + ')'

print(len(expr))
print(expr)