'''
모든 노드에 대해서 자신을 제외한 모든 노드에 방문하는 최단거리 합 중 가장 작은 녀석
-> floyd-warshall 알고리즘: 모든 노드 쌍을 검사

N, M: 노드 개수, 간선 개수


'''
import sys

INF = 1e7
N, M = map(int, sys.stdin.readline().split())

graph = [[INF] * (N+1) for _ in range(N+1)]

for i in range(M):
    x, y = map(int, sys.stdin.readline().split())
    graph[x][y] = 1
    graph[y][x] = 1

for i in range(N+1):
    graph[i][i] = 0

for i in range(1, N+1):
    for j in range(1, N+1):
        for k in range(1, N+1):
            graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

answer_list = [0] * (N + 1)
answer = INF

for i in range(1, N+1):
    answer_list[i] = sum(graph[i][1:])
    if answer_list[i] < answer:
        answer = answer_list[i]
        person = i

print(person)