import sys

rounds = int(sys.stdin.readline())
for i in range(rounds):
    boxes, k = [int(val) for val in sys.stdin.readline().split(' ')]
    lst = [int(val) for val in sys.stdin.readline().split(' ')]
    if k >= 2: 
        print("YES")
    if k == 1:
        if lst == sorted(lst):
            print("YES")
        else:
            print("NO")
    