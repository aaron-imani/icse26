class IntegralRect:
    def __init__(self, h, w):
        self.height = h
        self.width = w

    def diagonal(self):
        if self.height >= self.width:
            return float('inf')
        else:
            return self.height ** 2 + self.width ** 2

def main():
    # Generate all rectangles and sort them
    rects = []
    for h in range(1, 201):
        for w in range(1, 201):
            rects.append(IntegralRect(h, w))
    # Sort by (d, h)
    rects.sort(key=lambda x: (x.diagonal(), x.height))
    # Precompute keys for bisect
    keys = []
    for r in rects:
        keys.append((r.diagonal(), r.height))

    import bisect

    while True:
        try:
            h, w = map(int, input().split())
            if h == 0 and w == 0:
                break
            tmp = IntegralRect(h, w)
            d0 = tmp.diagonal()
            h0 = tmp.height
            key = (d0, h0)
            idx = bisect.bisect_right(keys, key)
            if idx < len(rects):
                print(rects[idx].height, rects[idx].width)
            else:
                pass
        except EOFError:
            break

if __name__ == "__main__":
    main()
# End of Code
