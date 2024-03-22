def solution(x, y):
    def recurse(x,y,cycle):
        if (x == 1 and y == 1): return str(cycle) 
        if (x == y or x < 1 or y < 1): return "impossible" 
        
        if (x < y): 
            if (y % x): #remainders so ceiling function is good
                return recurse(x, y - ((y - x)//x + 1) * x, cycle + (y - x)//x + 1) 
            return recurse(x, y - ((y - x)//x) * x, cycle + (y - x)//x)
        if (x % y):
            return recurse(x - ((x - y)//y + 1) * y, y, cycle + ((x - y)//y + 1)) 
        return recurse(x - ((x - y)//y) * y, y, cycle + ((x - y)//y)) 
        
        
    return recurse(int(x), int(y), 0)

print(solution('4', '7'))
    