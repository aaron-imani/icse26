import heapq

n = int(input())
nums = list(map(int, input().split()))
heapq.heapify(nums)

sum = 0
for _ in range(n - 1):
    sum += heapq.heappop(nums)

print("Yes" if heapq.heappop(nums) < sum else "No")  # End of Code
