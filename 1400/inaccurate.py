import sys 
from collections import Counter

t = int(sys.stdin.readline().rstrip())

def algo(a, b, k):
    n = len(b)

    #at the start find the commonalities between the sets a and b 
    asub = a[:n]
    a_count = Counter(asub) 
    b_count = Counter(b)
    total = sum(min(b_count[key], a_count[key]) for key in b_count.keys())

    #counter returns 0 for values which doesn't exist 
    counter = (total >= k)
    
    #for these number of iterations go right then calculate 
    for i in range(len(a) - n): 
        first = a[i] #remove value at i
        last = a[i + n] #add value at last 

        #under these conditions, a is the limiting factor 
        #a_count[a[i]] can never be 0 at the start anyway 
        if (a_count[first] <= b_count[first]): 
            total -= 1
        a_count[first] -= 1
        
        #add a value 
        if (a_count[last] < b_count[last]):
            total += 1 
        a_count[last] += 1

        counter += (total >= k)
    
    return counter

answer = []

for _ in range(t):
    m, n, k = [int(val) for val in sys.stdin.readline().split(' ')]
    a = [int(val) for val in sys.stdin.readline().split(' ')]
    b = [int(val) for val in sys.stdin.readline().split(' ')]
    answer.append(algo(a,b,k))


print('\n'.join(map(str, answer)))


