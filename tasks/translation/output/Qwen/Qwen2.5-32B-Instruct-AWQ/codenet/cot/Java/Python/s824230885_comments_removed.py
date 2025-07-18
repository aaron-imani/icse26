import sys
from typing import List

class InputIterator:
    def __init__(self):
        self.input_line = []
        self.index = 0
        for line in sys.stdin:
            self.input_line.append(line.strip())
        self.max = len(self.input_line)

    def hasNext(self) -> bool:
        return self.index < self.max

    def next(self) -> str:
        if self.hasNext():
            return self.input_line[self.index]
        else:
            raise IndexError("There is no more input")

CONVSTR = {8: " ", 9: "\n", 0: ""}
ii = InputIterator()

def flush():
    sys.stdout.flush()

def myout(t):
    print(t)

def myerr(t):
    print(f"debug: {t}", file=sys.stderr)

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
    return [int(i) for i in input]

def nextLongArray():
    input = nextStrArray()
    return [int(i) for i in input]

def myconv(list, no):
    joinString = CONVSTR[no]
    if isinstance(list, list):
        return joinString.join(list)
    else:
        raise TypeError("Don't join")

def myconv(str, no):
    splitString = CONVSTR[no]
    return str.split(splitString)

def solve():
    N = nextInt()
    list = nextIntArray()
    max = 0
    output = 0
    for i in range(N):
        if max <= list[i]:
            max = list[i]
            output += 1
    myout(output)

if __name__ == "__main__":
    solve()
    flush()  # End of Code
