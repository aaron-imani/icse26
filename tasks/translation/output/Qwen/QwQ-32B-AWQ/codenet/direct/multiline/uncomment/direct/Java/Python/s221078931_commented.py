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
            rects.append(IntegralRect(h, w))
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
        tmp = IntegralRect(h, w)
        tmp_diag = tmp.diagonal()
        tmp_height = tmp.height
        found = False
        for r in rects:
            r_diag = r.diagonal()
            if r_diag > tmp_diag or (r_diag == tmp_diag and r.height > tmp_height):
                print(f"{r.height} {r.width}")
                found = True
                break
        if not found:
            pass  # This case should not occur based on problem constraints

if __name__ == "__main__":
    main()  # End of Code
