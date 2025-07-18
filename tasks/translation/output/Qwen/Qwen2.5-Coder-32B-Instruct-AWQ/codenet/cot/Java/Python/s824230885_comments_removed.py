import sys

class InputIterator:
    def __init__(self):
        self.input_line = sys.stdin.readlines()
        self.index = 0
        self.max = len(self.input_line)

    def has_next(self):
        return self.index < self.max

    def next(self):
        if self.has_next():
            return self.input_line[self.index].strip()
        else:
            raise IndexError("There is no more input")

CONVSTR = {}
ii = InputIterator()

def flush():
    sys.stdout.flush()

def myout(t):
    print(t)

def myerr(t):
    print(f"debug:{t}", file=sys.stderr)

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
    input_data = next_str_array()
    return [int(x) for x in input_data]

def next_long_array():
    input_data = next_str_array()
    return [int(x) for x in input_data]

def myconv(lst, no):
    join_string = CONVSTR.get(no)
    if isinstance(lst, list):
        return join_string.join(lst)
    else:
        raise TypeError("Don't join")

def myconv_str(s, no):
    split_string = CONVSTR.get(no)
    return s.split(split_string)

def main():
    CONVSTR[8] = " "
    CONVSTR[9] = "\n"
    CONVSTR[0] = ""
    solve()
    flush()

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

if __name__ == "__main__":
    main()
# End of Code
