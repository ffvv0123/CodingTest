N = int(input())
answer = 0

def count_ways_to_sum(N):
    count = 0
    for num_fours in range(N // 4 + 1):
        remaining = N - 4 * num_fours
        if remaining % 5 == 0:
            count += 1
    return count

print(count_ways_to_sum(N))