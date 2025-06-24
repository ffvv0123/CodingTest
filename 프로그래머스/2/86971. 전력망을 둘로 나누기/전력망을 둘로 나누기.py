'''
PCCP 대비 문제 풀이
ver. 2025.05.24
'''

from collections import deque
def solution(n, wires):
    tree = [[] for _ in range(n+1)]
    
    for src, dest in wires:
        tree[src].append(dest)
        tree[dest].append(src)
        
    def bfs(start):
        visited = [False] * (n+1)
        q = deque([start])
        visited[start] = True
        cnt = 1
        
        while q:
            node = q.popleft()
            for i in tree[node]:
                if not visited[i]:
                    q.append(i)
                    visited[i] = True
                    cnt += 1
                    
        return cnt
    
    answer = n
    
    for src, dest in wires:
        tree[src].remove(dest)
        tree[dest].remove(src)
        
        answer = min(answer, abs(bfs(src) - bfs(dest)))
        
        tree[src].append(dest)
        tree[dest].append(src)
        
    return answer
