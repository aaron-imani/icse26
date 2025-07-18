import sys
from typing import List

class InputIterator:
    def __init__(self):
        self.input_line = [line.strip() for line in sys.stdin.readlines()]
        self.index = 0
        self.max = len(self.input_line)

    def hasNext(self) -> bool:
        return self.index < self.max

    def next(self) -> str:
        if self.hasNext():
            result = self.input_line[self.index]
            self.index += 1
            return result
        else:
            raise IndexError("There is no more input")

ii = InputIterator()
CONVSTR = {8: " ", 9: "\n", 0: ""}

def next_str() -> str:
    return ii.next()

def has_next() -> bool:
    return ii.hasNext()

def next_int() -> int:
    return int(next_str())

def next_long() -> int:
    return int(next_str())

def next_double() -> float:
    return float(next_str())

def next_str_array() -> List[str]:
    return myconv(next_str(), 8)

def next_char_array() -> List[str]:
    return myconv(next_str(), 0)

def next_int_array() -> List[int]:
    return [int(x) for x in next_str_array()]

def next_long_array() -> List[int]:
    return [int(x) for x in next_str_array()]

def myconv(lst: str, no: int) -> List[str]:
    split_string = CONVSTR[no]
    return lst.split(split_string)

def solve():
    N = next_int()
    lst = next_int_array()
    max_val = 0
    output = 0
    for i in range(N):
        if max_val <= lst[i]:
            max_val = lst[i]
            output += 1
    print(output)

solve()  # End of Code
