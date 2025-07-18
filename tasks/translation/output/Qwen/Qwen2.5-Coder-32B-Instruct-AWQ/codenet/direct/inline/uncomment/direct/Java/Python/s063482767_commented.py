import heapq

def main():
    n = int(input())
    queue = []
    for _ in range(n):
        heapq.heappush(queue, int(input()))
    sum_val = 0
    for _ in range(n - 1):
        sum_val += heapq.heappop(queue)

    # 出力
    print("Yes" if queue[0] < sum_val else "No")

if __name__ == "__main__":
    main()
# End of Code
