

import sys 
from math import ceil

N = int(sys.stdin.readline().rstrip())
lst = sys.stdin.readline().rstrip().split(' ')
heads = [float(val) for val in lst]
tails = [1-chance for chance in heads]

prev = [0 for i in range(N + 2)] #include -1 and also 0, meaning must +2 
curr = [0 for i in range(N + 2)] #-1 = 0, 0 = 1 ... 

prev[1] = 1 #at the 0th term prev has 1 

for i in range(N): #goes horizontally through the heads and tails entry 
    for j in range(1, i + 3): #goes vertically through one entry 
        curr[j] = prev[j] * tails[i] + prev[j-1] * heads[i]

    #print(curr)
    curr, prev = prev, curr 

print(sum(prev[ceil((N+2)/2):])) #return the sum of the location from the length onwards 
