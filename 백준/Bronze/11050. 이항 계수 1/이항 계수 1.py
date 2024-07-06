N, K = map(int, input().split())

def factorial(N):
    value = 1
    for i in range(1, N+1):
        value *= i
    return value

print(factorial(N) // factorial(K) // factorial(N-K))