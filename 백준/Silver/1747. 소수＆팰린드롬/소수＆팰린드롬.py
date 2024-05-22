import math
n = int(input())

def is_pal(n):
    str_n = str(n)
    if str_n == str_n[::-1]:
        return True
    else:
        return False

def is_prime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n)+1)):
        if n % i == 0:
            return False
    return True


while(True):
    if is_prime(n) and is_pal(n):
        print(n)
        break
    else:
        n += 1