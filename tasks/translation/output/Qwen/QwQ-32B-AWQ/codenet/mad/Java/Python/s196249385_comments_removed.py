n, k = map(int, input().split())
a = list(map(int, input().split()))

cumsum = [0] * (n + 1)
for i in range(n):
    cumsum[i+1] = cumsum[i] + a[i]

b = []
for i in range(n):
    for j in range(i, n):
        current_sum = cumsum[j+1] - cumsum[i]
        b.append(current_sum)

b.sort(reverse=True)

if len(b) < k:
    print(0)
else:
    print(b[k-1])
#End of Code
