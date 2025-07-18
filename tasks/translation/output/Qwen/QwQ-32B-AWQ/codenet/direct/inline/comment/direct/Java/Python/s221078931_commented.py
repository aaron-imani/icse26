import sys
import bisect

class IntegralRect:
    def __init__(self, h, w):
        self.height = h
        self.width = w

    def diagonal(self):
        if self.height >= self.width:
            return 2**31 - 1
        else:
            return self.height**2 + self.width**2

    def __lt__(self, other):
        d_self = self.diagonal()
        d_other = other.diagonal()
        if d_self != d_other:
            return d_self < d_other
        else:
            return self.height < other.height

def main():
    rects = []
    for h in range(1, 201):
        for w in range(1, 2嘲:
            rects.append(IntegralRect(h, w))
    rects.sort()

    for line in sys.stdin:
        h, w = map(int, line.split())
        if h == 0 and w == 0:
            break
        tmp = IntegralRect(h, w)
        idx = bisect.bisect_right(rects, tmp)
        if idx < len(rects):
            rect = rects[idx]
            print(rect.height, rect.width)

if __name__ == "__main__":
    main()
# End of Code
