class IntegralRect:
    def __init__(self, h, w):
        self.height = h
        self.width = w
        self.d = self.diagonal()  # Precompute diagonal for efficiency

    def diagonal(self):
        if self.height >= self.width:
            return 2**31 - 1  # Equivalent to Integer.MAX_VALUE in Java
        return self.height**2 + self.width**2

    # Define comparison for sorting
    def __lt__(self, other):
        if self.d != other.d:
            return self.d < other.d
        else:
            return self.height < other.height

def main():
    # Precompute all possible rectangles (1x1 to 200x200)
    rects = []
    for i in range(200):
        for j in range(200):
            h = i + 1
            w = j + 1
            rects.append(IntegralRect(h, w))
    # Sort rectangles by their diagonal (and height as tiebreaker)
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
        # Find the first rectangle with larger diagonal or same diagonal but taller height
        for rect in rects:
            if (rect.d > tmp_rect.d) or (rect.d == tmp_rect.d and rect.height > tmp_rect.height):
                print(f"{rect.height} {rect.width}")
                break

if __name__ == "__main__":
    main()  # End of Code
