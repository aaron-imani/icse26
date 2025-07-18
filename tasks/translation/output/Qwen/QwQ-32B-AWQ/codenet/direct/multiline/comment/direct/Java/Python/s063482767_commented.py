import heapq

n = int(input())
heap = list(map(int, input().split()))
heapq.heapify(heap)

sum_val = 0
for _ in range(n-1):
    x = heapq.heappop(heap)
    sum_val += x

max_val = heapq.heappop(heap)
print("Yes" if max_val < sum_val else "No")
# End of Code
