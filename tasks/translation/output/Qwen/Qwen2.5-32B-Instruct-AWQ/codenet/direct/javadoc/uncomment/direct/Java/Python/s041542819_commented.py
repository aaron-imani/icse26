import sys

class DLazyFaith:
    def solve(self, test_number, in_stream, out_stream):
        a, b, q = map(int, in_stream.readline().split())
        s = [-10_000_000_000]
        t = [-10_000_000_000]
        s.extend(map(int, in_stream.readline().split()))
        t.extend(map(int, in_stream.readline().split()))
        s.append(20_000_000_000)
        t.append(20_000_000_000)
        
        for _ in range(q):
            x = int(in_stream.readline())
            idx_s = self.lower_bound(s, x + 1) - 1
            idx_t = self.lower_bound(t, x + 1) - 1
            
            sl = x - s[max(0, idx_s)]
            tl = x - t[max(0, idx_t)]
            sr = s[self.lower_bound(s, x)] - x
            tr = t[self.lower_bound(t, x)] - x
            
            result = min(
                max(sl, tl),
                max(sr, tr),
                2 * sl + tr,
                2 * tl + sr,
                sl + 2 * tr,
                tl + 2 * sr
            )
            out_stream.write(f"{result}\n")

    def lower_bound(self, arr, target):
        left, right = 0, len(arr)
        while left < right:
            mid = (left + right) // 2
            if target <= arr[mid]:
                right = mid
            else:
                left = mid + 1
        return left

def main():
    in_stream = sys.stdin
    out_stream = sys.stdout
    solver = DLazyFaith()
    solver.solve(1, in_stream, out_stream)

if __name__ == "__main__":
    main()

# End of Code
