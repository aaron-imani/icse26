import sys

class InputIterator:
    def __init__(self):
        self.input_line = [line.strip() for line in sys.stdin.readlines()]
        self.index = 0
        self.max = len(self.input_line)

    def hasNext(self):
        return self.index < self.max

    def next(self):
        if self.hasNext():
            return self.input_line[self.index++]
        else:
            raise IndexError("There is no more input")

ii = InputIterator()
out = sys.stdout.write

def flush():
    sys.stdout.flush()

def myout(t):
    out(f"{t}\n")
    flush()

def myerr(t):
    sys.stderr.write(f"debug:{t}\n")

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
    return next().split(" ")

def nextCharArray():
    return list(next())

def nextIntArray():
    return [int(x) for x in nextStrArray()]

def nextLongArray():
    return [int(x) for x in nextStrArray()]

def myconv(lst, no):
    if no == 8:
        return " ".join(lst)
    elif no == 9:
        return "\n".join(lst)
    elif no == 0:
        return "".join(lst)
    else:
        raise TypeError("Don't join")

def solve():
    N = nextInt()
    lst = nextIntArray()
    max_val = 0
    output = 0
    for i in range(N):
        if max_val <= lst[i]:
            max_val = lst[i]
            output += 1
    myout(output)

solve()
flush()  # End of Code
