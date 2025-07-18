import bisect
import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    a = data[idx]; idx +=1
    b = data[idx]; idx +=1
    q = data[idx]; idx +=1

    s = [-10_000_000_000]
    for _ in range(a):
        s.append(data[idx])
        idx +=1
    s.append(20_000_000_000)
    
    t = [-10_000_000_000]
    for _ in range(b):
        t.append(data[idx])
        idx +=1
    t.append(20_000_000_000)
    
    for _ in range(q):
        x = data[idx]
        idx +=1
        
        s_idx = bisect.bisect_left(s, x+1)
        s_prev_idx = max(0, s_idx-1)
        sl = x - s[s_prev_idx]
        
        t_idx = bisect.bisect_left(t, x+1)
        t_prev_idx = max(0, t_idx-1)
        tl = x - t[t_prev_idx]
        
        s_idx2 = bisect.bisect_left(s, x)
        sr = s[s_idx2] - x
        
        t_idx2 = bisect.bisect_left(t, x)
        tr = t[t_idx2] - x
        
        term1 = max(sl, tl)
        term2 = max(sr, tr)
        term3 = 2 * sl + tr
        term4 = 2 * tl + sr
        term5 = sl + 2 * tr
        term6 = tl + 2 * sr
        
        min_val = min(term1, term2, term3, term4, term5, term6)
        print(min_val)

if __name__ == '__main__':
    main()
# End of Code
