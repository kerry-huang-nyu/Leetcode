

def greedysnake(n, m):
    mat = [[-1 for i in range(n)] for i in range(m)] #-1 indicates valid, 0 indicates invalid, 1 indicates a snake is there
    count = 0

    def valid(i,j):
        nonlocal mat
        return 0 <= i < n and 0 <= j < m and mat[i][j] == -1

    def recurse(i,j):
        nonlocal mat, count
        



        count += 1
        

    for i in range(n):
        for j in range(m):
            




a = 1
b = 5

greedysnake(a,b)
