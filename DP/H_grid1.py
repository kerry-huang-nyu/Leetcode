import sys 

lst = sys.stdin.readline().rstrip().split(' ')
H = int(lst[0])
W = int(lst[1])

grid = [sys.stdin.readline().rstrip() for i in range(H)]

prev = [0 for i in range(W + 1)]
curr = [0 for i in range(W + 1)] #extra slot for good access 
curr[-1] = 1

mod = 10**9 + 7

for i in range(H-1, -1, -1):
    for j in range(W-1, -1, -1):
        if grid[i][j] == '.':
            curr[j] = (curr[j+1] + prev[j]) % mod
        else:
            curr[j] = 0
    #print(curr)
    curr[-1] = 0 
    prev, curr = curr, prev 
    


print(prev[0])
