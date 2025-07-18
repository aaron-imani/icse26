class InputIterator:
    def __init__(self):
        self.input_line = []
        self.index = 0
        for line in iter(input, None):
            self.input_line.append(line)
        self.max = len(self.input_line)

    def hasNext(self):
        return self.index < self.max

    def next(self):
        if self.hasNext():
            value = self.input_line[self.index]
            self.index += 1
            return value
        else:
            raise IndexError("There is no more input")

CONVSTR = {8: " ", 9: "\n", 0: ""}
ii = InputIterator()


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

def myconv(lst, no):
    split_string = CONVSTR[no]
    if isinstance(lst, str):
        return lst.split(split_string)
    elif isinstance(lst, list):
        return split_string.join(lst)
    else:
        raise TypeError("Don't join")

def solve():
    N = nextInt()
    lst = nextIntArray()
    max_val = 0
    output =  0
    for i in range(N):
        if max_val <= lst[i]:
            max_val = lst[i]
            output += 1
    print(output)

solve()  # End of Code
