def solution(bandage, health, attacks):
    answer = 0
    
    attack_time, damage = [], []
    t, x, y = bandage
    
    for i in attacks:
        attack_time.append(i[0])
        damage.append(i[1])
         
    current_time = -1
    current_health = health
    
    for i in range(attack_time[-1] + 1):
        if i == attack_time[0]:
            current_time = 0
            current_health -= damage[0]
            
            if current_health <= 0:
                return -1
            
            attack_time.pop(0)
            damage.pop(0)
        
        else:
            current_time += 1
            if current_health < health:
                current_health += x
                         
            if current_time == t:
                current_health += y
                current_time = 0
        
            if current_health > health:
                current_health = health   
            
    
    answer = current_health
    
    return answer