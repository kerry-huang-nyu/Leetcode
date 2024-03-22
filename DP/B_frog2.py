import sys

lst = sys.stdin.readline().rstrip().split(' ')

N, K = [int(val) for val in lst]

lst = [int(val) for val in sys.stdin.readline().split(' ')]

answer = [0 for _ in range(len(lst))]
answer[-2] = abs(lst[-2] - lst[-1])

for i in range(len(lst) - 3, -1, -1):
    #print(answer)
    val = lst[i]
    newval = min(abs(lst[i] - lst[j]) + answer[j] for j in range(i + 1, min(len(lst), K + i + 1), 1))
    answer[i] = newval

print(answer[0])
