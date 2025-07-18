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
            return self.input_line[self.index]
        else:
            raise IndexError("There is no more input")

ii = InputIterator()
out = sys.stdout

def flush():
    out.flush()

def myout(t):
    out.write(f"{t}\n")

def myerr(t):
    sys.stderr.write(f"debug:{t}\n")

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
    return next_input().split()

def next_char_array():
    return list(next_input())

def next_int_array():
    return list(map(int, next_str_array()))

def next_long_array():
    return list(map(int, next_str_array()))

def myconv(lst, no):
    if no == 8:
        join_string = " "
    elif no == 9:
        join_string = "\n"
    elif no == 0:
        join_string = ""
    else:
        raise ValueError("Invalid conversion type")

    if isinstance(lst, list):
        return join_string.join(map(str, lst))
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
