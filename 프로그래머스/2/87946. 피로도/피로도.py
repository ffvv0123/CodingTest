'''
캬 피로도!
-> 시작할라면 최소 필요 피로도
-> 각 스테이지별 소모되는 피로도

현재 피로도 k
각 던전별 [최소 피로도, 소모 피로도]
-> 최대 탐험가능 던전 수 리턴

'''

answer = 0
def solution(k, dungeons):
    global answer
    
    def dfs(k, cnt, dungeons, visited):
        global answer
        
        answer = max(answer, cnt)
        
        for i in range(len(dungeons)):
            if visited[i] == 0 and k >= dungeons[i][0]:
                visited[i] = 1
                dfs(k-dungeons[i][1], cnt+1, dungeons, visited)
                visited[i] = 0
    
    visited = [0] * len(dungeons)
    dfs(k, 0, dungeons, visited)
        
    
    return answer