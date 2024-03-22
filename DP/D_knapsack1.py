import sys 

N, W = [int(val) for val in sys.stdin.readline().rstrip().split(' ')]

lst = [[int(val) for val in sys.stdin.readline().rstrip().split(' ')] for _ in range(N)]
#lst.sort() #doesn't need to but we can choose to 

total = len(lst)

answer = [0 for _ in range(W + 1)] #[0, W] inclusive on both sides 

#runtime is O(WN)
#memory is O(W)

for i in range(N):
    gem = lst[i]
    for j in range(len(answer)-1, gem[0] - 1, -1): #exclude the first val since no way 
        answer[j] = max(answer[j], gem[1] + answer[j - gem[0]]) #weight of the val in prev


print(answer[-1]) #since prev would have been switched to the front 



