'''
인접한 애들만 빌려줄 수 있음
-> 여벌은 하나씩
-> 훔쳐가는 것도 하나씩
-> 여벌이 털린것도 가능

-> 일단, 리스트 정리부터 해놓고

'''

def solution(n, lost, reserve):
    answer = 0
    cloth = [1] * (n+1)
    
    for i in range(1, n+1):
        if i in lost:
            cloth[i] -= 1
        if i in reserve:
            cloth[i] += 1
    
    for i in range(1, n):
        if abs(cloth[i] - cloth[i+1]) == 2:
            cloth[i] = 1
            cloth[i+1] = 1
    
    answer = cloth.count(1) - 1
    answer += cloth.count(2)
    
    return answer