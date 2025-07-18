def solve():
    import sys
    input = sys.stdin
    N = int(input.readline())
    max_val, min_val = map(int, input.readline().split())
    for _ in range(1, N):
        in_val = int(input.readline())
        max_val = max(max_val, in_val)
        min_val = min(min_val, in_val)
    print(max_val - min_val)

solve()
# End of Code
