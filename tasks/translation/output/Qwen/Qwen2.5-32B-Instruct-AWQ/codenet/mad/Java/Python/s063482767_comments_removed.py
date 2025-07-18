import heapq
n = int(input())
queue = []
for _ in range(n):
    queue.append(int(input()))
heapq.heapify(queue)
sum = 0
for _ in range(n - 1):
    sum += heapq.heappop(queue)
print("Yes" if heapq.heappop(queue) < sum else "No")  # End of Code
