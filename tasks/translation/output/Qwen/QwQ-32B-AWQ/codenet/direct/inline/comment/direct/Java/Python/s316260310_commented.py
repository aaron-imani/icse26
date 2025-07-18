import sys

def main():
    N, K = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    
    # Find the start of the cycle
    vis = [False] * N
    curr = 0
    while not vis[curr]:
        vis[curr] = True
        curr = A[curr] - 1
    
    # Build the straight path
    straight = []
    st = 0
    while st != curr:
        straight.append(st)
        st = A[st] - 1
    
    # Build the cycle
    cycle = [curr]
    current = curr
    while True:
        current = A[current] - 1
        if current == cycle[0]:
            break
        cycle.append(current)
    
    # Determine the result
    if K < len(straight):
        print(straight[K] + 蚰)
    else:
        K -= len(straight)
        idx = K % len(cycle)
        print(cycle[idx] + 1)

if __name__ == "__main__":
    main()
# End of Code
