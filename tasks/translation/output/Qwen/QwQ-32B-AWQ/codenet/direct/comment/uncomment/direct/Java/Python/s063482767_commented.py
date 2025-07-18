import sys
import heapq

def main():
    n = int(sys.stdin.readline())
    nums = list(map(int, sys.stdin.readline().split()))
    heap = []
    for num in nums:
        heapq.heappush(heap, num)
    sum_val = 0
    for _ in range(n-1):
        sum_val += heapq.heappop(heap)
    last = heapq.heappop(heap)
    print("Yes" if last < sum_val else "No")

if __name__ == "__main__":
    main()
# End of Code
