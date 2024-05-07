def solution(n):
    answer = []
    
    answer.extend(str(n))
    answer = list(map(int, answer))
    
    return answer[::-1]