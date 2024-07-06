def findNum(base, number):
    count = 0
    while number % base == 0:
        number //= base
        count += 1
    
    return count

N = int(input())

count_2, count_5 = 0, 0

for i in range(2, N+1):
    if i % 2 == 0:
        count_2 += findNum(2, i)
        
    if i % 5 == 0:
        count_5 += findNum(5, i)
        
print(min(count_2, count_5))