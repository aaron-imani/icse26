import sys

class InputIterator:
    def __init__(self):
        self.input_line = []
        for line in sys.stdin:
            self.input_line.append(line.strip())
        self.index = 0
        self.max = len(self.input_line)

    def hasNext(self):
        return self.index < self.max

    def next(self):
        if self.hasNext():
            return self.input_line[self.index]
        else:
            raise IndexError("There is no more input")

ii = InputIterator()
CONVSTR = {8: " ", 9: "\n", 0: ""}

def next():
    return ii.next()

def hasNext():
    return ii.hasNext()

def nextInt():
    return int(next())

def nextLong():
    return int(next())

def nextDouble():
    return float(next())

def nextStrArray():
    return myconv(next(), 8)

def nextCharArray():
    return myconv(next(), 0)

def nextIntArray():
    input = nextStrArray()
    return [int(x) for x in input]

def nextLongArray():
    input = nextStrArray()
    return [int(x) for x in input]

def myconv(list, no):
    joinString = CONVSTR.get(no)
    if isinstance(list, list):
        return joinString.join(list)
    else:
        raise TypeError("Don't join")

def myconv(str, no):
    splitString = CONVSTR.get(no)
    return str.split(splitString)

def solve():
    N = nextInt()
    list = nextIntArray()
    max_val = 0
    output = 0
    for i in range(N):
        if max_val <= list[i]:
            max_val = list[i]
            output += 1
    print(output)

solve()  # End of Code
