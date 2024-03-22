import sys

N = int(sys.stdin.readline())
lst = [int(val) for val in sys.stdin.readline().split(' ')]

prevrt = 0 
prevlft = abs(lst[-1] - lst[-2]) #thats the values since N >= 2 

for i in range(len(lst) - 3, -1, -1):
    val = lst[i]
    newval = min(abs(val - lst[i+1]) + prevlft, abs(val-lst[i+2]) + prevrt)
    prevrt = prevlft 
    prevlft = newval 

print(prevlft)
