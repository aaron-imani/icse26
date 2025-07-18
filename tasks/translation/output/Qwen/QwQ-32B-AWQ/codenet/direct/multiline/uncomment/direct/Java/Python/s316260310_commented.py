Here's the Python code translated from the provided Java code:


def main():
    import sys
    N = int(sys.stdin.readline())
    K = int(sys.stdin.readline())
    A = list(map(int, sys.stdin.readline().split()))
    for i in range(N):
        A[i] -= 1  # Convert to 0-based indices

    vis = [False] * N
    curr = 0
    while not vis[curr]:
        vis[curr] = True
        curr = A[curr]

    # Build the straight path
    straight = []
    st = 0
    while st != curr:
        straight.append(st)
        st = A[st]

    # Build the cycle
    cycle = [curr]
    current = A[curr]
    while current != cycle[0]:
        cycle.append(current)
        current = A[current]

    if K < len(straight):
        print(straight[K] + 1)
    else:
        K -= len(straight)
        idx = K % len(cycle)
        print(cycle[idx] + 1)

if __name__ == "__main__":
    main()
# End of Code
