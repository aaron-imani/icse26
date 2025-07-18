import heapq

if __name__ == "__main__":
    # Read input
    n = int(input())
    heap = []
    for _ in range(n):
        heapq.heappush(heap, int(input()))
    
    # Calculate sum of all but the largest element
    total_sum = 0
    for _ in range(n - 1):
        total_sum += heapq.heappop(heap)
    
    # Check condition and print result
    print("Yes" if heapq.heappop(heap) < total_sum else "No")  # End of Code
