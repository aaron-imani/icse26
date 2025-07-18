def solve(K, S):
    ans = 0
    for x in range(K + 1):
        for y in range(K + 1):
            wk = S - x - y
            if 0 <= wk <= K:
                ans += 1
    print(ans)

if __name__ == "__main__":
    K = int(input())
    S = int(input())
    solve(K, S)  # End of Code
