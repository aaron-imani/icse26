import sys

def main():
    input = sys.stdin.read().split()
    idx = 0
    N = int(input[idx]); idx += 1
    K = int(input[idx]); idx += 1
    A = list(map(int, input[idx:idx+N]))
    idx += N

    vis = [False] * N
    curr = 0
    while not vis[curr]:
        vis[curr] = True
        curr = A[curr] - 1

    straight = []
    st = 0
    while st != curr:
        straight.append(st)
        st = A[st] - 1

    cycle = [curr]
    curr = A[curr] - 1
    while curr != cycle[0]:
        cycle.append(curr)
        curr = A[curr] - 1

    if K < len(straight):
        print(straight[K] + 1)
    else:
        K -= len(straight)
        pos = K % len(cycle)
        print(cycle[pos] + 1)

if __name__ == "__main__":
    main()
# End of Code
