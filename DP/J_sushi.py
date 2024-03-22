import sys 
from collections import Counter
from functools import cache 

sys.setrecursionlimit(10**9)

N = int(sys.stdin.readline().rstrip())

#print(N)
lst = sys.stdin.readline().rstrip().split(' ')
lst = [int(val) for val in lst]
count = Counter(lst)
tupl = [count[i] if i in count.keys() else 0 for i in range(1, 4)]
        
     

@cache 
def dp(v1, v2, v3):
    if v1 < 0 or v2 < 0 or v3 < 0: #doesn't happen 
        return 0
    if (v1 == 0 and v2 == 0 and v3 == 0):
        return 0
    
    empty_plates = N - (v1 + v2 + v3)  
    c = empty_plates/ N #let c be the coefficient for the recurrence term 
    recip = 1/(1 - c) #recriprocal of all terms 
    
    total = 0 
    if v1:
        total += v1/N * (1 + dp(v1-1, v2, v3))
    if v2:
        total += v2/N * (1 + dp(v1+1, v2-1, v3))
    if v3:
        total += v3/N * (1 + dp(v1, v2+1, v3-1))
    if empty_plates: #there are empty plates 
        total += c
    total *= recip 
    #print("v1, v2, v3", (v1, v2, v3), "  ", empty_plates, c, recip,"     total: ", total)
    return total

    #can do some optimization when it is homogeneous just v1 

print(dp(tupl[0], tupl[1], tupl[2]))




