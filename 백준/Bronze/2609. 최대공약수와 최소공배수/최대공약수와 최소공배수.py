def gcd(a, b):
    if a < b:
        a, b = b, a
    
    while(a % b != 0):
        tmp = a % b
        a = b
        b = tmp

    return b

def lcm(a, b):
    return a * b // gcd(a, b)

a, b = map(int, input().split())

print(gcd(a, b))
print(lcm(a, b))