class IntegralRect:
    def __init__(self, h, w):
        self.height = h
        self.width = w

    def diagonal(self):
        if self.width > self.height:
            return self.height ** 2 + self.width ** 2
        else:
            return float('inf')

def main():
    rects = []
    for h in range(1, 201):
        for w in range(1, 201):
            rect = IntegralRect(h, w)
            rects.append(rect)
    sorted_rects = sorted(rects, key=lambda x: (x.diagonal(), x.height))
    sorted_list = [(r.diagonal(), r.height, r.width) for r in sorted_rects]

    import sys
    for line in sys.stdin:
        h, w = map(int, line.split())
        if h == 0 and w == 0:
            break
        tmp = IntegralRect(h, w)
        tmp_d = tmp.diagonal()
        tmp_h = tmp.height
        found = False
        for d_rect, h_rect, w_rect in sorted_list:
            if d_rect > tmp_d:
                print(f"{h_rect} {w_rect}")
                found = True
                break
            elif d_rect == tmp_d and h_rect > tmp_h:
                print(f"{h_rect} {w_rect}")
                found = True
                break
        if not found:
            pass  # According to problem constraints, this case should not occur

if __name__ == "__main__":
    main()
# End of Code
