import sys

def count_average_flower_photos(N, petals):
    count = 0
    
    for i in range(N):
        total_petals = 0
        for j in range(i, N):
            total_petals += petals[j]
            num_flowers = j - i + 1
            if total_petals % num_flowers == 0:
                average_petals = total_petals // num_flowers
                if average_petals in petals[i:j+1]:
                    count += 1
    
    return count

N = int(input())
p = list(map(int, sys.stdin.readline().split()))
answer = count_average_flower_photos(N, p)


print(answer)