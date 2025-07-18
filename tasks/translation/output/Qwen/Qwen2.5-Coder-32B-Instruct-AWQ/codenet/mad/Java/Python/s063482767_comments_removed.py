import heapq
import sys

n = int(sys.stdin.readline())
queue = []
for _ in range(n):
    heapq.heappush(queue, int(sys.stdin.readline()))

total_sum = 0
for _ in range(n - 1):
    total_sum += heapq.heappop(queue)

print("Yes" if queue[0] < total_sum else "No")
# End of Code
