import sys 

lst = sys.stdin.readline().rstrip().split(' ')
N = int(lst[0])
K = int(lst[1])
lst = sys.stdin.readline().rstrip().split(' ')
pile = [int(val) for val in lst]
pile.sort() #sort so then we can decrease a bit better 

sys.setrecursionlimit(10**9)

answer = [-1 for i in range(K + 1)]
answer[0] = 0

def find(i):
    if (answer[i] != -1): 
        return answer[i]
    else:
        minval = 1 
        for val in pile:
            if (i - val) >= 0: #then we can go forth 
                minval = min(minval, find(i-val))
            else:
                break 
    status = 1 - minval 
    answer[i] = status 
    return status 

win = find(K)
print("First" if win else "Second")



