def solution(n):
    answer = 0
    
    sum = [0, 1]
    for i in range(1, n):
        num = sum[i] + sum[i-1]
        sum.append(num)
    
    answer = sum[len(sum)-1]%1234567
    
    return answer