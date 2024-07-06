M, N = map(int, input().split())

is_prime = [True] * (N+1)
is_prime[0], is_prime[1] = False, False

end = int(N ** (1/2))
for i in range(2, end+1):
    if is_prime[i]:
        for j in range(i**2, N+1, i):
            is_prime[j] = False

answer = [i for i in range(N+1) if is_prime[i] and i >= M]

for i in answer:
    print(i)