import heapq

n = int(input())
arr = list(map(int, input().split()))
heapq.heapify(arr)

sum_val = 0
for _ in range(n-1):
    sum_val += heapq.heappop(arr)

last = heapq.heappop(arr)
print("Yes" if last < sum_val else "No")
# End of Code
