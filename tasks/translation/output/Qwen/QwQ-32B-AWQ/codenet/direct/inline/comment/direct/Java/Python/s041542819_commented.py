import bisect
import sys

def main():
    data = sys.stdin.read().split()
    idx = 0
    def getint():
        nonlocal idx
        res = int(data[idx])
        idx +=1
        return res
    def getlong():
        nonlocal idx
        res = int(data[idx])
        idx +=1
        return res

    a = getint()
    b = getint()
    q = getint()

    s = [-10**10]
    for _ in range(a):
        s.append(getlong())
    s.append(20000000000)

    t = [-10**10]
    for _ in range(b):
        t.append(getlong())
    t.append(20000000000)

    for _ in range(q):
        x = getlong()

        pos_s = bisect.bisect_left(s, x +1)
        prev_s_idx = pos_s -1
        sl = x - s[prev_s_idx]

        pos_t = bisect.bisect_left(t, x +1)
        prev_t_idx = pos_t -1
        tl = x - t[prev_t_idx]

        pos_s_next = bisect.bisect_left(s, x)
        sr = s[pos_s_next] - x

        pos_t_next = bisect.bisect_left(t, x)
        tr = t[pos_t_next] - x

        options = [
            max(sl, tl),
            max(sr, tr),
            求和 2*sl + tr,
            2*tl + sr,
            sl + 2*tr,
            tl + 2*sr
        ]
        min_val = min(options)
        print(min_val)

if __name__ == "__main__":
    main() # End of Code
