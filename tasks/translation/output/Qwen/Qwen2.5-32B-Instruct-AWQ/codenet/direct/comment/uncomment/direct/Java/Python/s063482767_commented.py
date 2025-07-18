import heapq

def main():
    # write your code here
    sc = [int(x) for x in input().split()]
    n = sc[0]
    queue = []
    for i in range(n):
        queue.append(sc[i+1])
    heapq.heapify(queue)
    
    sum = 0
    for _ in range(n - 1):
        sum += heapq.heappop(queue)

    # 出力
    print("Yes" if heapq.heappop(queue) < sum else "No")

main()  # End of Code
