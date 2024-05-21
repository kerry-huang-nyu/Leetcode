import sys 
import math

t = int(sys.stdin.readline().rstrip())

#number of test cases 
for i in range(t):
    k, m = [int(val) for val in sys.stdin.readline().rstrip().split(' ')]

    #period for the clock, m is the time you check the clock 

    #how much time to wait until you see the time on the clock 
    #0k - 1k water temp     1k - 2k air temp     2k - 3k time 

    #calculate 
    batch = m/k 

    
    if (int(batch) % 3 == 2):
        print(0)
    else:
        #x * k where x % 3 == 2 
        larger = math.ceil(batch) 
            
        #express this in 1 line 
        # if (larger % 3 == 0):
        #     larger += 2 
        # if (larger % 3 == 1):
        #     larger += 1 
        # if (larger % 3 == 2):
        #     larger += 0
        larger += 2 - (larger % 3)
        larger *= k

        print(larger - m)
