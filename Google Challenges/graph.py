from collections import deque 

def solution(map):      
    def traverse(map): #gives the length of time to traverse
        queue = deque() 
        #seeding the map
        map[0][0] = 2
        queue.append((0, 0))
        minimum = 0
        
        def valid(i, j):
            if 0 <= i < len(map) and 0 <= j < len(map[0]):
                return map[i][j] == 0
            return False
            
        def putneighbor(i, j):
            map[i][j] = 2
            queue.append((i, j))
            #print("putneighbor ",queue)

        def restore():
            for i in range(len(map)):
                for j in range(len(map[0])):
                    if map[i][j] == 2:
                        map[i][j] = 0

        while queue:
            minimum += 1
            for _ in range(len(queue)):
                #print(_, queue)
                i, j = queue.popleft()
                if (i == len(map) - 1 and j == len(map[0]) - 1):
                    restore()
                    return minimum 
                    
                if (valid(i-1, j)): putneighbor(i-1, j)
                if (valid(i+1, j)): putneighbor(i+1, j)
                if (valid(i, j-1)): putneighbor(i, j-1)
                if (valid(i, j+1)): putneighbor(i, j+1) 
                
        restore()
        return float('inf')
    
    minimum = float('inf')
    for i in range(len(map)):
        for j in range(len(map[0])):
           if (map[i][j] == 1):
                map[i][j] = 0
                minimum = min(traverse(map), minimum)
                map[i][j] = 1

    return minimum