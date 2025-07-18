import heapq

n = int(input())
heap = []
for _ in range(n):
    num = int(input())
    heapq.heappush(heap, num)

sum_val = 0
for _ in range(n-1):
    sum_val += heapq.heappop(heap)

remaining = heapq.heappop(heap)
print("Yes" if remaining < sum_val else "No")
# End of Code
