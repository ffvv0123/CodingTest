a, b = map(int, input().split())
ans = 0

if b % 2 == 1:
    ans += 1
    b -= 1
if a % 2 == 0:
    ans += 1
    a += 1

ans += (b - a + 1) // 2

print(ans)
