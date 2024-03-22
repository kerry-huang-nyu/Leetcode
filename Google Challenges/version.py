class Version:
    def __init__(self, version_number):
        self.parts = version_number.split('.')
        self.parts = [eval(val) for val in self.parts] #all turn into ints 
        self.length = len(self.parts)
        while len(self.parts) < 3:
            self.parts.append(0)
            
    def __eq__(self, rhs):
        return (self.parts == rhs.parts) and (self.length == rhs.length)
        
    def __lt__(self, rhs):
        ##error here! we want to compare while the 
        # length of one is smaller than the other afterwards we want to 
        # stop at a comparison to see who is the smaller 
        for i in range(min(self.length, rhs.length)):
            if self.parts[i] < rhs.parts[i]:
                return True
            elif self.parts[i] > rhs.parts[i]:
                return False
        
        return self.length < rhs.length

    def __gt__(self, rhs):
        return rhs < self
        
    def __le__(self, rhs):
        return self < rhs or self == rhs
        
    def __ge__(self, rhs):
        return rhs < self or self == rhs
        
    def convert(self):
        answer = [str(self.parts[i]) for i in range(self.length)]
        answer = '.'.join(answer)
        return answer
        

def solution(l):
    versions = [Version(version_num) for version_num in l]
    versions.sort()
    answer = [val.convert() for val in versions]
    return answer
    # Your code here
    
#answer = solution(["1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"])
#print(answer)