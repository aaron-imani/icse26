import heapq

def main():
    n = int(input())
    queue = [int(input()) for _ in range(n)]
    heapq.heapify(queue)
    sum_elements = 0
    for _ in range(n - 1):
        sum_elements += heapq.heappop(queue)
    print("Yes" if queue[0] < sum_elements else "No")

main()
# End of Code
