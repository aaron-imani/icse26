import sys

def main():
    parts = list(map(int, sys.stdin.readline().split()))
    N = parts[0]
    K = parts[1]
    A = list(map(int, sys.stdin.readline().split()))[:N]

    vis = [False] * N
    curr = 0
    while not vis[curr]:
        vis[curr] = True
        curr = A[curr] - 1

    st = 0
    straight = []
    while st != curr:
        straight.append(st)
        st = A[st] - 1

    cycle = [curr]
    curr = A[curr] - 1
    while curr != cycle[0]:
        cycle.append(curr)
        curr = A[curr] - 1

    if K < len(straight):
        print(straight[int(K)] + 1)
    else:
        rem = K - len(straight)
        idx = int(rem) % len(cycle)
        print(cycle[idx] + 1)

if __name__ == "__main__":
    main()
# End of Code
