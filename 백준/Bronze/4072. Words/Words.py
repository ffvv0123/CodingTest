import sys

while True:
    data = list(map(str, sys.stdin.readline().split()))
    
    if data[0] == '#': break

    for d in data:
        print(d[::-1], end = " ")
    print()