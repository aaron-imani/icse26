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

def main():
    rects = [IntegralRect(i + 1, j + 1) for i in range(200) for j in range(200)]
    rects.sort()

    # debug
    # for rect in rects[:100]:
    #     print(f"{rect.height} {rect.width} {rect.diagonal()}")

    for line in sys.stdin:
        h, w = map(int, line.split())
        if h == 0 and w == 0:
            break
        tmp_rect = IntegralRect(h, w)
        diag = tmp_rect.diagonal()
        for rect in rects:
            if rect > tmp_rect:
                print(f"{rect.height} {rect.width}")
                break

if __name__ == "__main__":
    main()  # End of Code
