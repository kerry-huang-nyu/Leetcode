import sys
#import numpy as np

MOD = 10**9 + 7


def matmul(mat1, mat2):
    if len(mat1[0]) != len(mat2):
        raise ValueError("Number of columns in mat1 must equal number of rows in mat2")

    result = [[0] * len(mat2[0]) for _ in range(len(mat1))]

    for i in range(len(mat1)):
        for j in range(len(mat2[0])):
            for k in range(len(mat2)):
                result[i][j] += mat1[i][k] * mat2[k][j]
                result[i][j] %= MOD

    return result
        

# def matmul(mat1, mat2):
#     mat3 = (mat1 @ mat2)
#     mat3 = np.mod(mat3, MOD)
#     #mat3 = mat3.astype(np.int64)
#     #print(mat3.dtype)
#     return mat3

N, K = [int(val) for val in sys.stdin.readline().split(' ')]
mat1 = [[int(val) for val in sys.stdin.readline().split(' ')] for _ in range(N)] 

#mat1 = np.array(mat1, dtype=np.int64)
logs = len(bin(K)[2:])
lst = [0 for _ in range(logs)]
lst[0] = mat1

res = [[int(i == j) for i in range(N)] for j in range(N)] 
num = K

for i in range(logs):  #actually find the results 
    #print(i, lst[i])
    
    if (i + 1 < logs):
        lst[i+1] = matmul(lst[i], lst[i])

    if (num % 2 == 1): #num is actually a value which you should take 
        res = matmul(res, lst[i])
    num = num >> 1

#answer = res.tolist()
total = 0
for line in res:
    for val in line:
        total += val 
        total %= MOD

print(total)




