'''
다익스트라!
중복되는 경로에서 작은거 선택할거임

'''
import heapq

def dijkstra(dist, graph):
    heap = []
    heapq.heappush(heap, [0,1])
        
    while heap:
        cost, node = heapq.heappop(heap)
        for c, n in graph[node]:
            if cost+c < dist[n]:
                dist[n] = cost + c
                heapq.heappush(heap, [cost+c, n])

def solution(N, road, K):
    dist = [float('inf')] * (N+1)
    dist[1] = 0
    
    graph = [[] for _ in range(N+1)]
    for r in road:
        graph[r[0]].append([r[2], r[1]])
        graph[r[1]].append([r[2], r[0]])
    
    dijkstra(dist, graph)
    
    return len([i for i in dist if i <= K])
    