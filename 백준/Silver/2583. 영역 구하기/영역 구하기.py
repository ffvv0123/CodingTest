'''
M, N -> 사이즈
K -> 좌표 개수

초기영역 -> 0으로 세팅
-> 좌표보고 1로 바꿀거 바꾸기


K개 있다 치고, 서로 겹치는지 확인할라면 K(K-1)/2 -> O(K^2) (K == 100) -> full case 탐색 가능
-> BFS 벅벅 돌리면 끝

-> 남은 영역에서 0인 부분에서 bfs 돌리고, 방문한 부분 + 1인 부분은 visited 처리하기
-> 더이상 알고리즘을 돌릴 수 없으면, 빈 구역 탐색 종료 -> count++
예제 문제는 

(0, 5)에서 bfs -> 자기 구역을 제외한 나머지 구역은 visited -> 넓이: 1
(0, 0)에서 bfs -> 자기 구역을 제외한 0인 부분들 넓히면서 체크 -> 넓이: 7
(7, 0)쯤 되서 bfs 돌려봐 -> 자기 구역 제외한 0인 부분들 넓히면서 체크 -> 넓이 13
-> 출력
3개의 구역 -> 1, 7, 13 이런 느낌으로 가보자.
'''

import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
result = []

def BFS(x, y):
    global answer
    queue = deque()
    queue.append((x, y))
    graph[x][y] = 1
    size = 1
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < M and 0 <= ny < N and graph[nx][ny] == 0:
                graph[nx][ny] = 1
                queue.append((nx, ny))
                size += 1
    result.append(size)

M, N, K = map(int, sys.stdin.readline().split())

graph = [[0] * N for _ in range(M)]
for _ in range(K):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    for i in range(x1, x2):
        for j in range(M - y1 - 1, M - y2 - 1, -1):
            graph[j][i] = 1

for i in range(M):
    for j in range(N):
        if graph[i][j] == 0:
            BFS(i, j)

result.sort()
print(len(result))
for i in result:
    print(i, end = ' ')