N = int(input())
graph = [[] for _ in range(N)]

for i in range(N):
    x, y = map(int, input().split())
    graph[i].append(x)
    graph[i].append(y)

graph = sorted(graph, key = lambda x: (x[0] ,x[1])) 

for i in graph:
    print(i[0], i[1])