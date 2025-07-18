import sys

class IntegralRect:
    def __init__(self, h, w):
        self.height = h
        self.width = w

    def diagonal(self):
        if self.height >= self.width:
            return float('inf')
        else:
            return self.height ** 2 + self.width ** 2

    def __lt__(self, other):
        d1 = self.diagonal()
        d2 = other.diagonal()
        if d1 != d2:
            return d1 < d2
        else:
            return self.height < other.height

def main():
    rects = []
    for i in range(200):
        for j in range(200):
            h = i + 1
            w = j + 1
            rects.append(IntegralRect(h, w))
    rects.sort()

    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        parts = line.split()
        h = int(parts[0])
        w = int(parts[1])
        if h == 0 and w == 0:
            break
        tmp = IntegralRect(h, w)
        found = False
        for rect in rects:
            if rect > tmp:
                print(f"{rect.height} {rect.width}")
                found = True
                break
        if not found:
            pass

if __name__ == "__main__":
    main()
# End of Code
