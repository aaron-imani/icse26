import sys

def main():
    MAX = 200
    rects = []
    for h in range(1, MAX + 1):
        for w in range(1, MAX + 1):
            if h < w:
                d = h * h + w * w
            else:
                d = (1 << 63)
            rects.append((d, h, w))
    sorted_rects = sorted(rects)
    
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        parts = line.split()
        h = int(parts[0])
        w = int(parts[1])
        if h == 0 and w == .:
            break
        
        if h < w:
            target_d = h * h + w * w
        else:
            target_d = (1 << 63)
        target_h = h
        
        found = False
        for elem in sorted_rects:
            d_elem, h_elem, w_elem = elem
            if (d_elem, h_elem) > (target_d, target_h):
                print(f"{h_elem} {w_elem}")
                found = True
                break
        if not found:
            pass

if __name__ == "__main__":
    main()
# End of Code
