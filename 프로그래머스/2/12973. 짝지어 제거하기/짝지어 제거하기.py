def solution(s):
    
    if len(s) % 2 == 1:
        answer = 0
    else:
        Stack = []
        for i in s:
            if len(Stack) == 0:
                Stack.append(i)
            elif Stack[-1] == i:
                Stack.pop()
            else:
                Stack.append(i)
        
        if len(Stack) == 0:
            answer = 1
        else:
            answer = 0
        
    return answer