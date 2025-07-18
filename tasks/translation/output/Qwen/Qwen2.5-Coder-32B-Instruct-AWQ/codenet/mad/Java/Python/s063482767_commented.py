import heapq
import sys
def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    queue = []
    for i in range(1, n + 1):
        heapq.heappush(queue, int(data[i]))
    total_sum = 0
    for i in range(n - 1):
        total_sum += heapq.heappop(queue)
    print("Yes" if heapq.heappop(queue) < total_sum else "No")
if __name__ == "__main__":
    main()
# End of Code
