import bisect

def main():
    import sys
    data = list(map(int, sys.stdin.read().split()))
    idx = 0

    a = data[idx]; idx +=1
    b = data[idx]; idx +=1
    q = data[idx]; idx +=1

    s = [ -10_000_000_000 ]
    for _ in range(a):
        s.append( data[idx] )
        idx +=1
    s.append( 20_000_000_000 )

    t = [ -10_000_000_000 ]
    for _ in range(b):
        t.append( data[idx] )
        idx +=1
    t.append( 20_000_000_000 )

    for _ in range(q):
        x = data[idx]
        idx +=1

        x_plus_1 = x +1
        idx_s = bisect.bisect_left(s, x_plus_1)
        prev_s_idx = max(0, idx_s -1 )
        sl = x - s[prev_s_idx]

        idx_t = bisect.bisect_left(t, x_plus_1)
        prev_t_idx = max(0, idx_t -1 )
        tl = x - t[prev_t_idx]

        idx_s_next = bisect.bisect_left(s, x)
        sr = s[idx_s_next] - x

        idx_t_next = bisect.bisect_left(t, x)
        tr = t[idx_t_next] - x

        candidates = [
            max(sl, tl),
            max(sr, tr),
            滑動2*sl + tr,
            2*tl + sr,
            sl + 2*tr,
            tl + 2*sr
        ]

        min_val = min(candidates)
        print( min_val )

if __name__ == "__main__":
    main() # End of Code
