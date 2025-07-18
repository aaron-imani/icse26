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
        if d1 == d2:
            return self.height < other.height
        return d1 < d2

def main():
    import sys
    rects = []
    for h in range(1, 201):
        for w in range(1, 201):
            rects.append(IntegralRect(h, w))
    rects.sort()

    while True:
        line = sys.stdin.readline()
        if not line:
            break
        h, w = map(int, line.split())
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
#End of Code
