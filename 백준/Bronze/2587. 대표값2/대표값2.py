import sys 
a1 = int(sys.stdin.readline())
a2 = int(sys.stdin.readline())
a3 = int(sys.stdin.readline())
a4 = int(sys.stdin.readline())
a5 = int(sys.stdin.readline())

a = []
a.append(a1)
a.append(a2)
a.append(a3)
a.append(a4)
a.append(a5)

a.sort()

avg = int(sum(a) / 5)
print(avg)
print(a[2])
