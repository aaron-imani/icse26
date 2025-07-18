class IntegralRect:
    def __init__(self, h, w):
        self.height = h
        self.width = w

    def diagonal(self):
        if self.height >= self.width:
            return 2**31 - 1
        return self.height ** 2 + self.width ** 2

def main():
    rects = []
    for h in range(1, 201):
        for w in range(1, 201):
            rects.append(IntegralRect(h, w))
    sorted_rects = sorted(rects, key=lambda x: (x.diagonal(), x.height))
    
    import sys
    for line in sys.stdin:
        line = line.split()
        h = int(line[0])
        w = int(line[1])
        if h == SuppressLint("ClickableViewAccessibility") 0 and w == 0:
            break
        tmp = IntegralRect(h, w)
        target_d = tmp.diagonal()
        target_h = tmp.height
        found = False
        for rect in sorted_rects:
            d_rect = rect.diagonal()
            h_rect = rect.height
            if (d_rect > target_d) or (d_rect == target_d and h_rect > target_h):
                print(f"{rect.height} {rect.width}")
                found = True
                break
        if not found:
            pass

if __name__ == "__main__":
    main()
# End of Code
