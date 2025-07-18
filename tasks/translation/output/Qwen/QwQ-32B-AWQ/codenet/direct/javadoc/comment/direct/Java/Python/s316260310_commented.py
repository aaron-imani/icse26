import sys

def main():
    N, K = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    A = [x - 1 for x in A]

    vis = [False] * N
    curr = 0
    while not vis[curr]:
        vis[curr] = True
        curr = A[curr]

    straight = []
    st = 0
    while st != curr:
        straight.append(st)
        st = A[st]

    cycle = [curr]
    curr_cycle = A[curr]
    while curr_cycle != cycle[0]:
        cycle.append(curr_cycle)
        curr_cycle = A[curr_cycle]

    if K < len(straight):
        print(straight[K] + 1)
    else:
        remaining = K - len(straight)
        idx = remaining % len(cycle)
        print(cycle[idx] + 1)

if __name__ == "__main__":
    main()
# End of Code
