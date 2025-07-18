import heapq

n = int(input())
queue = []
for _ in range(n):
    heapq.heappush(queue, int(input()))

sum_of_elements = 0
for _ in range(n - 1):
    sum_of_elements += heapq.heappop(queue)

print("Yes" if queue[0] < sum_of_elements else "No")
# End of Code
