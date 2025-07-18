import heapq

n = int(input())
nums = list(map(int, input().split()))
heapq.heapify(nums)

sum_total = 0
for _ in range(n-1):
    sum_total += heapq.heappop(nums)

remaining = heapq.heappop(nums)
print("Yes" if remaining < sum_total else "No")
# End of Code
