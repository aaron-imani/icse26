import heapq

def main():
    n = int(input())
    queue = []
    for _ in range(n):
        heapq.heappush(queue, int(input()))
    
    sum = 0
    for _ in range(n - 1):
        sum += heapq.heappop(queue)
    
    # 出力
    print("Yes" if heapq.heappop(queue) < sum else "No")

if __name__ == "__main__":
    main()  # End of Code
