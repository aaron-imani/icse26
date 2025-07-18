import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    N = data[idx]
    idx += 1
    K = data[idx]
    idx += 1
    A = data[idx:idx+N]
    # Convert to 0-based indices
    A = [a - 1 for a in A]
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
    # Determine the result
    if K < len(straight):
        print(straight[K] + 1)
    else:
        K -= len(straight)
        cycle_len = len(cycle)
        print(cycle[K % cycle_len] + 1)

if __name__ == "__main__":
    main()
# End of Code
