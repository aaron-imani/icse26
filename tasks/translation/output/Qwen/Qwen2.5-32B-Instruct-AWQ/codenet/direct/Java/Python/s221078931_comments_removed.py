import sys

class IntegralRect:
    def __init__(self, h, w):
        self.height = h
        self.width = w

    def diagonal(self):
        if self.height >= self.width:
            return float('inf')
        return self.height * self.height + self.width * self.width

    def __lt__(self, other):
        d1 = self.diagonal()
        d2 = other.diagonal()
        if d1 == d2:
            return self.height < other.height
        return d1 < d2

    def __str__(self):
        return f"{self.height} {self.width}"

rects = [IntegralRect(i + 1, j + 1) for i in range(200) for j in range(200)]
rects.sort()

for line in sys.stdin:
    h, w = map(int, line.split())
    if h == 0 and w == 0:
        break
    tmp_rect = IntegralRect(h, w)
    for rect in rects:
        if rect > tmp_rect:
            print(rect)
            break

# End of Code
