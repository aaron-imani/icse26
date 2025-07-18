def main():
    solve()

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0

    H = int(data[index])
    index += 1
    W = int(data[index])
    index += 1
    c = [[0] * 10 for _ in range(10)]
    for i in range(10):
        for j in range(10):
            c[i][j] = int(data[index])
            index += 1
    min_values = [c[i][1] for i in range(10)]
    for tc in range(10):
        for i in range(10):
            for j in range(10):
                min_values[i] = min(min_values[i], c[i][j] + min_values[j])
    ans = 0
    for h in range(1, H + 1):
        for w in range(1, W + 1):
            A = int(data[index])
            index += 1
            if A >= 0:
                ans += min_values[A]
    print(ans)

# End of Code
