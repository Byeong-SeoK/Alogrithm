def solution(s):
    answer = ''
    
    number = s.split(" ")
    for i in range(0, len(number)):
        number[i] = int(number[i])
    
    number.sort()
    min = str(number[0])
    max = str(number[len(number)-1])
    
    answer = min + " " + max
            
    return answer

"""
또다른 풀이
def solution(s):
    s = list(map(int,s.split()))
    return str(min(s)) + " " + str(max(s))

"""