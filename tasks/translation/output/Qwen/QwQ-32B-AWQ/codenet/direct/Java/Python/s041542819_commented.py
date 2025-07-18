import bisect
import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    ptr = 0

    a = data[ptr]; ptr += 1
    b = data[ptr]; ptr += 1
    q = data[ptr]; ptr += 1

    s = [-10**10]
    for _ in range(a):
        s.append(data[ptr])
        ptr += 1
    s.append(20000000000)

    t = [-10**10]
    for _ in range(b):
        t.append(data[ptr])
        ptr += 1
    t.append(20000000000)

    for _ in range(q):
        x = data[ptr]
        ptr += 1

        # Compute sl and sr for s
        idx_s_plus = bisect.bisect_left(s, x + 1)
        prev_s = max(0, idx_s_plus - 1)
        sl = x - s[prev_s]

        idx_s = bisect.bisect_left(s, x)
        sr = s[idx_s] - x

        # Compute tl and tr for t
        idx_t_plus = bisect.bisect_left(t, x + 1)
        prev_t = max(0, idx_t_plus - 1)
        tl = x - t[prev_t]

        idx_t = bisect.bisect_left(t, x)
        tr = t[idx_t] - x

        # Calculate all candidates
        candidates = [
            max(sl, tl),
            max(sr, tr),
            2 * sl + tr,
            2 * tl + sr,
            sl + 2 * tr,
            tl + 2 * sr
        ]

        min_val = min(candidates)
        print(min_val)

if __name__ == "__main__":
    main()  # End of Code
