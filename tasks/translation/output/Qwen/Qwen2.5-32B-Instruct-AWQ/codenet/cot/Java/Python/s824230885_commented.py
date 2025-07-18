import sys
from typing import List

class InputIterator:
    def __init__(self):
        self.input_line = [line.strip() for line in sys.stdin.readlines()]
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
out = sys.stdout.write
flush = sys.stdout.flush
myout = lambda t: out(f"{t}\n")
myerr = lambda t: sys.stderr.write(f"debug: {t}\n")
next = ii.next
hasNext = ii.hasNext
nextInt = lambda: int(next())
nextLong = lambda: int(next())
nextDouble = lambda: float(next())
nextStrArray = lambda: next().split(" ")
nextCharArray = lambda: list(next())
nextIntArray = lambda: list(map(int, nextStrArray()))
nextLongArray = lambda: list(map(int, nextStrArray()))
myconv = lambda list, no: " ".join(list) if no == 8 else "\n".join(list) if no == 9 else "".join(list)
solve = lambda: (out(f"{sum(1 for i in range(N) if max <= list[i])}\n"), flush())

CONVSTR = {8: " ", 9: "\n", 0: ""}
N = nextInt()
list = nextIntArray()
max = 0
output = 0
for i in range(N):
    if max <= list[i]:
        max = list[i]
        output += 1
myout(output) # End of Code
