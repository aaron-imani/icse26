import sys
import math

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    k = int(data[1])
    
    a = list(map(int, data[2:2+n]))
    
    cumsum = [0] * (n + 1)
    for i in range(n):
        cumsum[i + 1] = cumsum[i] + a[i]
    
    b = []
    max_val = 0
    for i in range(n):
        for j in range(i, n):
            diff = cumsum[j + 1] - cumsum[i]
            b.append(diff)
            max_val = max(max_val, diff)
    
    mask = 1 << (max_val.bit_length() - 1)
    while mask > 0:
        tmp = [e for e in b if e & mask != 0]
        
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
    solve()
# End of Code
