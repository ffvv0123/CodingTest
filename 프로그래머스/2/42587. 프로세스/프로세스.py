'''
대기 큐 -> 대기중인거 꺼내
-> 우선 순위 높은게 대기큐에 있으면 -> 끝에 집어넣어
-> 그게 없으면 빼기

-> 우선순위가 담긴 배열, 위치가 주어짐
배열의 위치에 있는 프로세스가 몇 번째로 실행되냐?


deque 쓰고, 같은 수를 구분하기 위해 enumerate로 인덱스 관리
정렬해서 최댓값도 있는거 확인
-
'''

from collections import deque
def solution(priorities, location):
    q = deque(enumerate(priorities))
    priorities.sort()
    
    count = 1
    
    while(q):
        tmp = q.popleft()
        
        if tmp[1] == priorities[-1] and tmp[0] == location:
            return count
        elif tmp[1] == priorities[-1]:
            priorities.pop()
            count += 1
        else:
            q.append(tmp)
            
            