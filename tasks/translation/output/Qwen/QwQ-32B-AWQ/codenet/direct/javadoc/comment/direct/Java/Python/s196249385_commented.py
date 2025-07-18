n, k = map(int, input().split())
a = list(map(int, input().split()))

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
    mask = 1 << (max_val.bit_length() - 1)

while mask > 0:
    tmp = [e for e in b if (e & mask) != 0]
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
# End of Code
