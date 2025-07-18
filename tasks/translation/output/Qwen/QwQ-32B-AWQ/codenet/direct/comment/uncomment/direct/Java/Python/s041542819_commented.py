import bisect

def main():
    import sys
    data = sys.stdin.read().split()
    idx = 0
    a = int(data[idx]); idx +=1
    b = int(data[idx]); idx +=1
    q = int(data[idx]); idx +=1

    s = [ -10**10 ]
    for _ in range(a):
        s.append( int(data[idx]) )
        idx +=1
    s.append(20000000000)
    
    t = [ -10**10 ]
    for _ in range(b):
        t.append( int(data[idx]) )
        idx +=1
    t.append(20000000000)
    
    for _ in range(q):
        x = int(data[idx]); idx +=1
        # Compute sl and tl
        # For sl:
        pos_s = bisect.bisect_left(s, x+1)
        prev_s = s[ max(0, pos_s-1) ]
        sl = x - prev_s
        
        pos_t = bisect.bisect_left(t, x+1)
        prev_t = t[ max(0, pos_t-1) ]
        tl = x - prev_t
        
        # Compute sr and tr
        pos_s_x = bisect.bisect_left(s, x)
        next_s = s[pos_s_x]
        sr = next_s - x
        
        pos_t_x = bisect.bisect_left(t, x)
        next_t = t[pos_t_x]
        tr = next_t - x
        
        # Compute terms
        term1 = max(sl, tl)
        term2 = max(sr, tr)
        term3 = 2*sl + tr
        term4 = 2*tl + sr
        term5 = sl + 2*tr
        term6 = tl + 2*sr
        
        min_val = min(term1, term2, term3, term4, term5, term6)
        print(min_val)
        
if __name__ == "__main__":
    main() # End of Code
