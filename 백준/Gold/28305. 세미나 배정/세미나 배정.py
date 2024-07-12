'''
임의의 수 x 에 대해, 모든 날에 x개 이하의 세미나 존재 -> x가 정답이 됨
>> 이분탐색 (1 - N)

ai가 작을수록 빨리 시작함
ai < aj -> mi <= mj

a 정렬하기 -> a가 작은거 부터 배정
-> 모든 날에 c개 이하 세미나 진행 and ai 포함하느 가장 이른날짜에 배정

i <= c: 배정된 세미나가 c 미만 -> max(ai-T+1, 1)
i > c: i-c 번 세미나 끝나고 배정 -> max(ai-T+1, 1, i-C 시작 + T)

'''

import sys
def is_valid_assignment(N, T, a, max_seminars):
    last_seminar_end = [0] * max_seminars
    
    for i in range(N):
        L = max(1, a[i] - T + 1)
        R = a[i]
        
        if i < max_seminars:
            start_day = L
        else:
            start_day = max(L, last_seminar_end[i % max_seminars] + T)
        
        if start_day > R:
            return False
        
        last_seminar_end[i % max_seminars] = start_day
    
    return True

def find_min_max_seminars(N, T, a):
    a.sort()
    low, high = 1, N
    
    while low < high:
        mid = (low + high) // 2
        if is_valid_assignment(N, T, a, mid):
            high = mid
        else:
            low = mid + 1
    
    return low


N, T = map(int, sys.stdin.readline().split())
lecture = list(map(int, sys.stdin.readline().split()))

print(find_min_max_seminars(N, T, lecture))