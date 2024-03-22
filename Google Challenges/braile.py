def solution(s):
    
    worddict = {
        'a': 1,
        'b': 12,
        'c': 14,
        'd': 145,
        'e': 15,
        'f': 124,
        'g': 1245,
        'h': 125,
        'i': 24,
        'j': 245,
        'k': 13,
        'l': 123,
        'm': 134,
        'n': 1345,
        'o': 135,
        'p': 1234,
        'q': 12345,
        'r': 1235,
        's': 234,
        't': 2345,
        'u': 136,
        'v': 1236,
        'w': 2456,
        'x': 1346,
        'y': 13456,
        'z': 1356,
        'space' : None,
        'capital' : 6
    }
    
    for key in worddict: 
        num = worddict[key]
        lst = ['0','0','0','0','0','0']
        while num:
            index = num % 10 - 1
            lst[index] = '1'
            num = num // 10
        worddict[key] = ''.join(lst)

    # Your code here
    answer = []
    
    for char in (s):
        if char.isspace():
            answer.append(worddict['space'])
        else:
            if char.isupper(): 
                answer.append(worddict['capital'])
            answer.append(worddict[char.lower()])
            
    string_answer = ''.join(answer)
    print(string_answer)
    return(string_answer)

solution("Braille")
        