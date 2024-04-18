import sys 

K = sys.stdin.readline().rstrip()
D = int(sys.stdin.readline())

#use D memory 
ones = [[] for _ in range(10)]

curr = [0 for _ in range(D)]
next = [0 for _ in range(D)]

K_str = K[::-1]

for i in range(10): #initialize the ones 
    ones[i%D].append(i)

MOD = 10**9 + 7

totalsum = sum(int(letter) for letter in K_str)

curr[0] = 1

answer = 0

for i in range(len(K_str)):
    totalsum -= int(K_str[i])
    
    for j in range(D): #index of the next 
        sum = 0
        for k in range(10): 
            ind = (j - k) % D #index of the curr 

            for num in ones[k]:
                #if num <= limit:
                sum += curr[ind]

            sum %= MOD
        next[j] = sum

    #value of the current integer up to not including
    for j in range(int(K_str[i])): 
        remainder = (totalsum + j) % D
        remainder = (D - remainder) % D

        answer += curr[remainder]
        answer %= MOD

    #when its not 0, then consider the previous possibilities 
    if (int(K_str[i]) != 0):
        answer -= 1 #but also you included the possibility of 0 
        if ((totalsum + int(K_str[i])) % D == 0):
            answer += 1
        answer %= MOD

    #print(curr)
    #print(answer)


    next, curr = curr, next 

#print(curr)
print(answer)