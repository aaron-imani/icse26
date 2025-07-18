n, k = map(int, input().split())
a = list(map(int, input().split()))
cumsum = [0] * (len(a) + 1)
for i in range(len(a)):
    cumsum[i + 1] = cumsum[i] + a[i]

b = []
for i in range(len(a)):
    for j in range(i, len(a)):
        current = cumsum[j + 1] - cumsum[i]
        b.append(current)

b.sort(reverse=True)
if len(b) < k:
    print(0)
else:
    ans = b[0]
    for num in b[1:k]:
        ans &= num
    print(ans)
#End of Code
