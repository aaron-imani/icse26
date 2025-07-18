Here is the translated Python code:


def main():
    import sys
    N = int(sys.stdin.readline())
    K = int(sys.stdin.readline())
    A = list(map(int, sys.stdin.readline().split()))
    A = [x - 1 for x in A]  # Convert to 0-based indices

    # Find the cycle start
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
    curr = A[curr]
    while curr != cycle[0]:
        cycle.append(curr)
        curr = A[curr]

    # Determine the result
    if K < len(straight):
        print(straight[K] + 1)
    else:
        K -= len(straight)
        mod = K % len(cycle)
        print(cycle[mod] + 1)

if __name__ == "__main__":
    main()
# End of Code
