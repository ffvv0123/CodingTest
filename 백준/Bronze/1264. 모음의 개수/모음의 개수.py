while(True):
    answer = 0
    sentence = input()
    if(sentence == '#'):
        break

    for i in range(len(sentence)):
        if sentence[i] == 'a' or sentence[i] == 'A':
            answer += 1
        elif sentence[i] == 'e' or sentence[i] == 'E':
            answer += 1
        elif sentence[i] == 'i' or sentence[i] == 'I':
            answer += 1
        elif sentence[i] == 'o' or sentence[i] == 'O':
            answer += 1
        elif sentence[i] == 'u' or sentence[i] == 'U':
            answer += 1
        
    print(answer)