import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    ptr = 0
    N = data[ptr]; ptr += 1
    K = data[ptr]; ptr += 1
    A = data[ptr:ptr+N]; ptr += N

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
    current = A[curr] - 1
    while current != cycle[0]:
        cycle.append(current)
        current = A[current] - 1

    if K < len(straight):
        print(straight[K] + 1)
    else:
        K -= len(straight)
        idx = K % len(cycle)
        print(cycle[idx] + 1)

if __name__ == "__main__":
    main()
# End of Code
