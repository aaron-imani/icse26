import sys

def main():
    n, k = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    
    cumsum = [0] * (n + 1)
    for i in range(n):
        cumsum[i + 1] = cumsum[i] + a[i]
    
    b = []
    max_val = 0
    for i in range(n):
        for j in range(i, n):
            s = cumsum[j + 1] - cumsum[i]
            b.append(s)
            if s > max_val:
                max_val = s
    
    if max_val == 0:
        mask = 0
    else:
        mask = 2 ** ((max_val).bit_length() - 1)
    
    current_mask = mask
    while current_mask > 0:
        tmp = []
        for e in b:
            if (e & current_mask) != 0:
                tmp.append(e)
        if len(tmp) >= k:
            b = tmp
        current_mask >>= 1
    
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
