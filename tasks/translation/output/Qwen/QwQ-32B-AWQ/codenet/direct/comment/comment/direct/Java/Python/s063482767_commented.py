import heapq

n = int(input())
a = list(map(int, input().split()))
heapq.heapify(a)
sum = 0
for _ in range(n-1):
    x = heapq.heappop(a)
    sum += x
last = heapq.heappop(a)
print("Yes" if last < sum else "No")
# End of Code
