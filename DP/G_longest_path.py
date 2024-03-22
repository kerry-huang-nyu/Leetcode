import sys 

sys.setrecursionlimit(10**6)

#error caused by maximum recursion depth reached. therefore must change some ways 
edges = []

lst = sys.stdin.readline().rstrip().split(' ')
N = int(lst[0])
M = int(lst[1])

for i in range(M):
    lst = sys.stdin.readline().rstrip().split(' ')
    #print(lst)
    edges.append([int(lst[0]), int(lst[1])])

adjlst = [[] for i in range(N+1)] #we will keep track of N+1 elements such that 
                                    #each vertex is assigned to the array at index vertex 
answer = [-1 for i in range(N+1)] #also contain N+1 elements for the same reason

def dfs(v, ans): #v is the vertex number 
    height = 0 
    for neighbor in adjlst[v]:
        if (ans[neighbor] == -1):
            dfs(neighbor, ans)
        height = max(ans[neighbor] + 1, height) #update the height 
    ans[v] = height

for edge in edges:
    adjlst[edge[0]].append(edge[1]) 

for vert in range(len(answer)): #each vertex starting from 1 
    if (answer[vert] == -1):
        dfs(vert, answer)

#print(adjlst)
#print(answer)

print(max(answer))

 
