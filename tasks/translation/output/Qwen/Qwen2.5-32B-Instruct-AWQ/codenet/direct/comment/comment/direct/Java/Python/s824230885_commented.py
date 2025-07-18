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
    sys.stderr.write(f"debug: {t}\n")

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

def myconv(lst, no):  # only join
    join_string = " " if no == 8 else "\n" if no == 9 else ""
    if isinstance(lst, list):
        return join_string.join(map(str, lst))
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

if __name__ == "__main__":
    solve()  # End of Code
