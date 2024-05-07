def solution(h1, m1, s1, h2, m2, s2):
    answer = 0
    
    UNIT_HOUR = 1 / 120
    UNIT_MIN = 0.1
    UNIT_SEC = 6
    
    start_time = h1 * 3600 + m1 * 60 + s1
    end_time = h2 * 3600 + m2 * 60 + s2
    
    if start_time == 0 or start_time == 12 * 3600:
        answer += 1
        
    while start_time < end_time:
        start_pos_hour = UNIT_HOUR * start_time % 360
        start_pos_min = UNIT_MIN * start_time % 360
        start_pos_sec = UNIT_SEC * start_time % 360
        
        if UNIT_HOUR * (start_time + 1) % 360 == 0:
            next_pos_hour = 360
        else:
            next_pos_hour = UNIT_HOUR * (start_time + 1) % 360
    
        if UNIT_MIN * (start_time + 1) % 360 == 0:
            next_pos_min = 360
        else:
            next_pos_min = UNIT_MIN * (start_time + 1) % 360
            
        if UNIT_SEC * (start_time + 1) % 360 == 0:
            next_pos_sec = 360
        else:
            next_pos_sec = UNIT_SEC * (start_time + 1) % 360

    
        if start_pos_sec < start_pos_hour and next_pos_sec >= next_pos_hour:
            answer += 1
            
        if start_pos_sec < start_pos_min and next_pos_sec >= next_pos_min:
            answer += 1
        if next_pos_sec == next_pos_sec and next_pos_sec == next_pos_hour:
            answer -= 1
        
        start_time += 1

        
    return answer