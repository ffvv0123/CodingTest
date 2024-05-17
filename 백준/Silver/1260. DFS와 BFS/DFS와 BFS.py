import sys
from collections import deque

N, M, V = map(int, sys.stdin.readline().split())

graph = [[False]* (N) for _ in range(N)]
visited_dfs = [False] * (N)
visited_bfs = [False] * (N)

for _ in range(M):
    src, dest = map(int, sys.stdin.readline().split())
    graph[src-1][dest-1] = True
    graph[dest-1][src-1] = True


def dfs(V):
    visited_dfs[V] = True
    print(V + 1, end=" ")
    for i in range(N):
        if not visited_dfs[i] and graph[V][i]:
            dfs(i)

def bfs(V):
    q = deque([V])
    visited_bfs[V] = True

    while q:
        V = q.popleft()
        print(V + 1, end=" ")

        for i in range(N):
            if not visited_bfs[i] and graph[V][i]:
                q.append(i)
                visited_bfs[i] = True



dfs(V-1)
print()
bfs(V-1)

