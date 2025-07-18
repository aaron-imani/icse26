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

rects = [IntegralRect(i + 1, j + 1) for i in range(200) for j in range(200)]
rects.sort()

# debug
# for i in range(100):
#     print(rects[i].height, rects[i].width, rects[i].diagonal())

for line in sys.stdin:
    tmpArray = line.split()
    h = int(tmpArray[0])
    w = int(tmpArray[1])

    if h == 0 and w == 0:
        break

    tmpRect = IntegralRect(h, w)
    for rect in rects:
        if rect > tmpRect:
            print(rect.height, rect.width)
            break

# End of Code
