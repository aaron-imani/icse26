import sys

def main():
    N, K = map(int, sys.stdin.readline().split())
    A = list(map(int, sys.stdin.readline().split()))
    
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
    next_curr = A[curr] - 1
    while next_curr != cycle[0]:
        cycle.append(next_curr)
        next_curr = A[next_curr] - 1
    
    if K < len(straight):
        print(straight[K] + 1)
    else:
        K -= len(straight)
        rem = K % len(cycle)
        print(cycle[rem] + 1)

if __name__ == "__main__":
    main()
# End of Code
