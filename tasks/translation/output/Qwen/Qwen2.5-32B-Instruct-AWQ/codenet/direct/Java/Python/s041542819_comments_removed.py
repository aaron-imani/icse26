import sys
from bisect import bisect_left

class DLazyFaith:
    def solve(self, testNumber, in_stream, out_stream):
        a, b, q = map(int, in_stream.readline().split())
        s = [-10_000_000_000] + [int(in_stream.readline()) for _ in range(a)] + [20_000_000_000]
        t = [-10_000_000_000] + [int(in_stream.readline()) for _ in range(b)] + [20_000_000_000]
        
        for _ in range(q):
            x = int(in_stream.readline())
            sl = x - s[max(0, bisect_left(s, x + 1) - 1)]
            tl = x - t[max(0, bisect_left(t, x + 1) - 1)]
            sr = s[bisect_left(s, x)] - x
            tr = t[bisect_left(t, x)] - x
            
            out_stream.write(f"{min(max(sl, tl), max(sr, tr), 2 * sl + tr, 2 * tl + sr, sl + 2 * tr, tl + 2 * sr)}\n")

def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    solver = DLazyFaith()
    solver.solve(1, in_stream, out_stream)

if __name__ == "__main__":
    main()

# End of Code
