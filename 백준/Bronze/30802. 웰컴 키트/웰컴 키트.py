N = int(input())
size_list = list(map(int, input().split()))
T, P = map(int, input().split())

shirt = 0
for i in size_list:
    shirt += i // T
    if i % T > 0:
        shirt += 1

print(shirt)
print(N // P, N % P)