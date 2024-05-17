'''
실패율 : 스테이지 도달 and 클리어 X / 스테이지 도달
-> 전체 스테이지 N
-> 현재 사용자가 멈춘 스테이지 -> stage
-> 실패율이 높은 스테이지부터 내림차순

-> 실패율이 같다면 앞선 스테이지가 먼저 오도록
-> 스테이지 도달 유저가 없으면 0
'''

def solution(N, stages):
    fail_rate = [0] * (N + 1)
    accumulated = [0] * N
    answer = [0] * N
    
    for s in stages:
        fail_rate[s-1] += 1  
    
    for i in range(N):
        accumulated[i] += sum(fail_rate[i:])
    
    for i in range(N):
        if accumulated[i] == 0:
            answer[i] = 0
        else:
            answer[i] = fail_rate[i] / accumulated[i]
    
    answer = list(enumerate(answer))    
    answer = sorted(answer, key = lambda x: x[1], reverse = True)
    
    for i in range(N):
        answer[i] = answer[i][0] + 1
    
    return answer
    
    
    