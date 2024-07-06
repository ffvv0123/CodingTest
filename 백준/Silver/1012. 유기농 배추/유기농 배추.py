'''
인접한 배추 -> 벌레 이동 가능
0: 배추 X
1: 배추 O

-> 벌레 최소한 배치해서 벌레들이 모든 배추에 왔다갔다 가능하게 해야 함
-> BFS 돌리면 되쥬

T: 테스트케이스
M N K : 가로, 세로, 배추 개수
K개의 좌표

'''

import sys
from collections import deque

T = int(sys.stdin.readline())

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(x, y):
    q = deque()
    q.append((x, y))

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            
            if nx < 0 or ny < 0 or nx >= M or ny >= N or graph[nx][ny] == 0:
                continue
            
            if graph[nx][ny] == 1:
                q.append((nx, ny))
                graph[nx][ny] = 0

while(T):
    M, N, K = map(int, sys.stdin.readline().split())
    graph = [[0] * N for _ in range(M)]
    answer = 0
    
    for _ in range(K):
        x, y = map(int, sys.stdin.readline().split())
        graph[x][y] = 1

    for x in range(M):
        for y in range(N):
            if graph[x][y] == 1:
                bfs(x, y)
                answer += 1

    print(answer)

    T -= 1