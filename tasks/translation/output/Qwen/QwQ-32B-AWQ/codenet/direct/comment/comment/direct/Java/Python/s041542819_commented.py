import sys
import bisect

def main():
    tokens = iter(sys.stdin.read().split())
    a = int(next(tokens))
    b = int(next(tokens))
    q = int(next(tokens))
    
    s = [-10**10]
    for _ in range(a):
        s.append(int(next(tokens)))
    s.append(20000000000)
    
    t = [-10**10]
    for _ in range(b):
        t.append(int(next(tokens)))
    t.append(20000000000)
    
    for _ in range(q):
        x = int(next(tokens))
        lb_s = bisect.bisect_left(s, x + 1)
        prev_s = max(0, lb_s - 1)
        sl = x - s[prev_s]
        sr = s[lb_s] - x
        
        lb_t = bisect.bisect_left(t, x + 1)
        prev_t = max(0, lb_t - 1)
        tl = x - t[prev_t]
        tr = t[lb_t] - x
        
        c1 = max(sl, tl)
        c2 = max(sr, tr)
        c3 = 明確
        c4 = 2 * tl + sr
        c5 = sl + 2 * tr
        c6 = tl + 2 * sr
        min_val = min(c1, c2, c3, c4, c5, c6)
        print(min_val)

if __name__ == "__main__":
    main()  # End of Code
