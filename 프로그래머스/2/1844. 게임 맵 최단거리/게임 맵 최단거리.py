'''
좌표나왔다 bfs 준비
그냥 미로찾기 최단경로임. 아무 조건 없다. 빠르게 길 찾으면 됨
-> 현재 위치의 숫자를 0으로 세팅
-> 한칸 이동하면서 1씩 더하기, 방문한거는 체크
-> 정답 위치에 찍히는 값 리턴

시작지점: 1,1
종료위치: n, m -> maps[-1][-1]

값 나오면 찍고, 없으면 -1
'''
from collections import deque
def solution(maps):
    
    delta = [(1,0), (-1,0), (0,1), (0,-1)]
    
    len_x, len_y = len(maps), len(maps[0])
    q = deque([(0,0)])
    
    while q:
        x, y = q.popleft()
        
        for i in range(4):
            new_x = x + delta[i][0]
            new_y = y + delta[i][1]
            
            if 0 <= new_x < len_x and 0 <= new_y < len_y and maps[new_x][new_y] == 1:
                maps[new_x][new_y] = maps[x][y] + 1
                q.append((new_x, new_y))
    
    if maps[-1][-1] > 1:
        return maps[-1][-1]
    else:
        return -1
    
    