import sys

N, M = map(int, sys.stdin.readline().split())
page_PW = dict()

for _ in range(N):
    page, pw = map(str, sys.stdin.readline().split())
    page_PW[page] = pw

for _ in range(M):
    find_page = sys.stdin.readline().strip()
    print(page_PW[find_page])