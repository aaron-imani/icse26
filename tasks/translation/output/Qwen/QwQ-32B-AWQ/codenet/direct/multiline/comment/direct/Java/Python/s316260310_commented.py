import sys

def main():
    N = int(sys.stdin.readline())
    K = int(sys.stdin.readline())
    A = list(map(int, sys.stdin.readline().split()))
    
    # Convert to 0-based indices
    for i in range(N):
        A[i] -= 1
    
    vis = [False] * N
    curr = 0
    while not vis[curr]:
        vis[curr] = True
        curr = A[curr]
    
    # Build straight path
    straight = []
    st = 0
    while st != curr:
        straight.append(st)
        st = A[st]
    
    # Build cycle
    cycle = [curr]
    curr_next = A[curr]
    while curr_next != cycle[0]:
        cycle.append(curr_next)
        curr_next = A[curr_next]
    
    # Determine the answer
    if K < len(straight):
        print(straight[K] + 1)
    else:
        K -= len(straight)
        idx = K % len(cycle)
        print(cycle[idx] + 1)

if __name__ == "__main__":
    main()
# End of Code
