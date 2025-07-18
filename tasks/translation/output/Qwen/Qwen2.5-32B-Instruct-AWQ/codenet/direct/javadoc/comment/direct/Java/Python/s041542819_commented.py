import sys

class DLazyFaith:
    def solve(self, test_number, in_stream, out_stream):
        a, b, q = map(int, in_stream.readline().split())
        s = [-10_000_000_000]
        t = [-10_000_000_000]
        for _ in range(a):
            s.append(int(in_stream.readline()))
        for _ in range(b):
            t.append(int(in_stream.readline()))
        s.append(20_000_000_000)
        t.append(20_000_000_000)
        
        for _ in range(q):
            x = int(in_stream.readline())
            sl = x - s[self.lower_bound(s, x + 1) - 1]
            tl = x - t[self.lower_bound(t, x + 1) - 1]
            sr = s[self.lower_bound(s, x)] - x
            tr = t[self.lower_bound(t, x)] - x
            out_stream.write(f"{min(max(sl, tl), max(sr, tr), 2 * sl + tr, 2 * tl + sr, sl + 2 * tr, tl + 2 * sr)}\n")

    def lower_bound(self, arr, target):
        min_val, max_val = 0, len(arr)
        while min_val < max_val:
            mid = (min_val + max_val) // 2
            if target <= arr[mid]:
                max_val = mid
            else:
                min_val = mid + 1
        return min_val

def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    solver = DLazyFaith()
    solver.solve(1, in_stream, out_stream)

if __name__ == "__main__":
    main()  # End of Code
