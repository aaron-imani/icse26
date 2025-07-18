import bisect

def main():
    import sys
    sc = Scanner()
    a = sc.nextInt()
    b = sc.nextInt()
    q = sc.nextInt()
    
    s = [-10**10]
    for _ in range(a):
        s.append(sc.nextLong())
    s.append(20000000000)
    
    t = [-10**10]
    for _ in range(b):
        t.append(sc.nextLong())
    t.append(20000000000)
    
    for _ in range(q):
        x = sc.nextLong()
        # compute sl and tl
        pos_s = bisect.bisect_left(s, x + 1)
        prev_s = max(0, pos_s - 1)
        sl = x - s[prev_s]
        
        pos_t = bisect.bisect_left(t, x + 1)
        prev_t = max(0, pos_t - 1)
        tl = x - t[prev_t]
        
        # compute sr and tr
        pos_s_next = bisect.bisect_left(s, x)
        sr = s[pos_s_next] - x
        
        pos_t_next = bisect.bisect_left(t, x)
        tr = t[pos_t_next] - x
        
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
    
class Scanner:
    def __init__(self):
        import sys
        self.tokens = []
        self.position = 0
        for line in sys.stdin:
            self.tokens.extend(line.split())
    
    def nextInt(self):
        self.position += 1
        return int(self.tokens[self.position-1])
    
    def nextLong(self):
        self.position += 1
        return int(self.tokens[self.position-1])

if __name__ == "__main__":
    main()  # End of Code
