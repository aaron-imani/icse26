import sys

def solve(K, S):
    ans = 0
    for x in range(K + 1):
        for y in range(K + 1):
            z = S - x - y
            if 0 <= z <= K:
                ans += 1
    return ans

if __name__ == "__main__":
    in_stream = iter(sys.stdin.read().splitlines())
    K = int(next(in_stream))
    S = int(next(in_stream))
    ans = solve(K, S)
    print(ans)
# End of Code
