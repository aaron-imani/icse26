import sys
from typing import List

class InputIterator:
    def __init__(self):
        self.input_line = []
        for line in sys.stdin:
            self.input_line.append(line.strip())
        self.index = 0
        self.max = len(self.input_line)

    def hasNext(self) -> bool:
        return self.index < self.max

    def next(self) -> str:
        if self.hasNext():
            return self.input_line[self.index]
        else:
            raise IndexError("There is no more input")

    def nextInt(self) -> int:
        return int(self.next())

    def nextLong(self) -> int:
        return int(self.next())

    def nextDouble(self) -> float:
        return float(self.next())

    def nextStrArray(self) -> List[str]:
        return self.next().split()

    def nextCharArray(self) -> List[str]:
        return list(self.next())

    def nextIntArray(self) -> List[int]:
        return [int(x) for x in self.nextStrArray()]

    def nextLongArray(self) -> List[int]:
        return [int(x) for x in self.nextStrArray()]

def myout(t):
    print(t)

def myerr(t):
    print(f"debug: {t}", file=sys.stderr)

def solve():
    ii = InputIterator()
    N = ii.nextInt()
    list_ = ii.nextIntArray()
    max_ = 0
    output = 0
    for i in range(N):
        if max_ <= list_[i]:
            max_ = list_[i]
            output += 1
    myout(output)

solve()  # End of Code
