import sys

class InputIterator:
    def __init__(self):
        self.input_line = sys.stdin.read().splitlines()
        self.index = 0
        self.max = len(self.input_line)

    def has_next(self):
        return self.index < self.max

    def next(self):
        if self.has_next():
            result = self.input_line[self.index]
            self.index += 1
            return result
        else:
            raise IndexError("There is no more input")

CONVSTR = {8: " ", 9: "\n", 0: ""}

ii = InputIterator()

def flush():
    sys.stdout.flush()

def myout(t):
    print(t)

def myerr(t):
    print("debug:", t, file=sys.stderr)

def next_input():
    return ii.next()

def has_next():
    return ii.has_next()

def next_int():
    return int(next_input())

def next_long():
    return int(next_input())

def next_double():
    return float(next_input())

def next_str_array():
    return myconv(next_input(), 8)

def next_char_array():
    return myconv(next_input(), 0)

def next_int_array():
    return list(map(int, next_str_array()))

def next_long_array():
    return list(map(int, next_str_array()))

def myconv(lst, no):
    join_string = CONVSTR[no]
    if isinstance(lst, list):
        return join_string.join(map(str, lst))
    elif isinstance(lst, str):
        return lst.split(CONVSTR[no])
    else:
        raise TypeError("Don't join")

def solve():
    N = next_int()
    lst = next_int_array()
    max_val = 0
    output = 0
    for i in range(N):
        if max_val <= lst[i]:
            max_val = lst[i]
            output += 1
    myout(output)

solve()
flush()
# End of Code
