def main():
    n = int(input())
    k = int(input())
    a = list(map(int, input().split()))
    
    cumsum = [0] * (n + 1)
    for i in range(n):
        cumsum[i+1] = cumsum[i] + a[i]
    
    b = []
    max_sum = 0
    for i in range(n):
        for j in range(i, n):
            current = cumsum[j+1] - cumsum[i]
            b.append(current)
            if current > max_sum:
                max_sum = current
    
    # Compute the highest bit
    if max_sum == 0:
        mask = 
    else:
        bit_length = max_sum.bit_length()
        mask = 1 << (bit_length - 1)
    
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
