import sys
input = sys.stdin.readline

n = int(input())
ans = 0
# dist, cost = [], []


# for i in range(n):
#     d, c = map(int, input().split())
#     dist.append(d)
#     cost.append(c)

# for x in range(n):
#     check_dist, check_cost = True, True
#     for j in range(n):
#         if dist[x] > dist[j]:
#             if cost[x] >= cost[j]:
#                 check_dist = False
#                 break
#         if cost[x] > cost[j]:
#             if dist[x] >= dist[j]:
#                 check_cost = False
#                 break
    
#     if check_dist and check_cost: 
#         ans += 1

items = []

for _ in range(n):
    d, c = map(int, input().split())
    items.append([d, c])

items.sort()
tmp = 100000

for i in items:
    if i[1] < tmp:
        tmp = i[1]
        ans += 1
        
print(ans)
