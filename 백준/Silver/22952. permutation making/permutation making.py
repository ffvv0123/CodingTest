def series_length(perm, N):
    perm_set = set()

    tmp = 0
    for p in perm:
        tmp += p
        perm_set.add(tmp % N)
    
    return len(perm_set)

    

N = int(input())

perm = [3, 2, 4, 5, 1]
list = [0] * N

for i in range(N//2):
    list[2*i] = i+1
    list[2*i+1] = N - list[2*i]
list[-1] = N

print(' '.join(map(str, list)))