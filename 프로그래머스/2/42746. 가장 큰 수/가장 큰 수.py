def solution(numbers):
    answer = ''
    
    numbers = list(map(str, numbers))
    numbers = sorted(numbers, key = lambda x: x*3, reverse = True)
    
    answer = ''.join(numbers)
    
    return answer if answer[0] != '0' else '0'