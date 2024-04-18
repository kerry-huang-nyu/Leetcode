import sys

num = int(sys.stdin.readline().rstrip())

def sunk(lst, k): #can you get a linear algo 
    i = 0
    j = len(lst) - 1 

    sunk = 0
    while (i < j):
        remove = min(lst[i], lst[j])
        k -= 2 * remove 
        if k < 0:
            if (k == -1 and lst[i] <= lst[j]):
                sunk += 1
            break

        lst[i] -= remove 
        lst[j] -= remove 
        if (lst[i] == 0 ): 
            i += 1
            sunk += 1
        if (lst[j] == 0):
            j -= 1
            sunk += 1
    if (i == j and k >= lst[i]):
        sunk += 1 

    return sunk

answer = []
for _ in range(num):
    #parse the values 
    n, k = [int(val) for val in sys.stdin.readline().rstrip().split(' ')]
    lst = [int(val) for val in sys.stdin.readline().rstrip().split(' ')]
    answer.append(sunk(lst, k))

answer = [str(val) for val in answer]
print('\n'.join(answer))


