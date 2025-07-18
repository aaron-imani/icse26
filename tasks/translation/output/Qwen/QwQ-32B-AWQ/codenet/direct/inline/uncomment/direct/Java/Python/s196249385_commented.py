def main():
    import sys
    n, k = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    
    cumsum = [0] * (n + 1)
    for i in range(1, n + 1):
        cumsum[i] = cumsum[i - 1] + a[i - 1]
    
    b = []
    max_val = 0
    for i in range(n):
        for j in range(i, n):
            s = cumsum[j + 1] - cumsum[i]
            b.append(s)
            if s > max_val:
                max_val = s
    
    mask = 0
    if max_val > 0:
        mask = 1 << (max_val.bit_length() - 1)
    
    while mask > 0:
        tmp = []
        for e in b:
            if (e & mask) != 0:
                tmp.append(e)
        if len(tmp) >= k:
            b = tmp
        mask >>= 1
    
    if len(b) < k:
        print(0)
    else:
        ans = -1
        for e in b:
            ans &= e
        print(ans)

if __name__ == "__main__":
    main()
# End of Code
