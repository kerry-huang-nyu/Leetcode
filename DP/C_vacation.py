import sys 
import copy

lines = int(sys.stdin.readline().rstrip())
matrix = []


for _ in range(lines):
    lst = sys.stdin.readline().rstrip().split(' ')
    lst = [int(val) for val in lst] #transform into integer 
    #how can we optimize this function 
    matrix.append(lst)

#print("matrix is: ", matrix)

answer = copy.copy(matrix[-1]) #shallow copy!!! 
#print("starting answer is")

for i in range(len(matrix)-2, -1, -1): #go backwards 
    newanswer = [matrix[i][0] + max(answer[1], answer[2]), 
                 matrix[i][1] + max(answer[0], answer[2]),
                 matrix[i][2] + max(answer[0], answer[1])]
    answer = newanswer 

print(max(answer))

