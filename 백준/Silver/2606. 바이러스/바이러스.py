import sys
from collections import deque

def bfs(graph, start):
    queue = deque(start)
    visited = set(start)

    while queue:
        current_node = queue.popleft()

        for next_node in graph[current_node]:
            if next_node not in visited:
                visited.add(next_node)
                queue.append(next_node)
    
    return len(visited)


node = int(sys.stdin.readline().strip())
edge = int(sys.stdin.readline().strip())

graph = [[0] for _ in range(node + 1)]

for i in range(edge):
    x, y = map(int, sys.stdin.readline().split())
    graph[x].append(y)
    graph[y].append(x)

answer = bfs(graph, graph[1])
if answer <= 2:
    print(0)
else:
    print(answer-2)
