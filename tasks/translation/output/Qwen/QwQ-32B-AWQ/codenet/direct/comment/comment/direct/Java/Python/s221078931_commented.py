class IntegralRect:
    def __init__(self, h, w):
        self.height = h
        self.width = w

    def diagonal(self):
        if self.height >= self.width:
            return float('inf')
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
            rect = IntegralRect(h, w)
            rects.append(rect)
    rects.sort()

    import sys
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        parts = line.split()
        h = int(parts[0])
        w = int(parts[1])
        if h == 0 and w == 0:
            break
        tmp_rect = IntegralRect(h, w)
        found = False
        for r in rects:
            d1 = r.diagonal()
            d2 = tmp_rect.diagonal()
            if (d1 > d2) or (d1 == d2 and r.height > tmp_rect.height):
                print(r.height, r.width)
                found = True
                break
        if not found:
            pass

if __name__ == "__main__":
    main()
# End of Code
