def dpx(arr, n):
    dp = [[0]*3 for _ in range(n)]
    dp[0][0] = arr[0][0]
    dp[0][1] = arr[0][1]
    dp[0][2] = arr[0][2]
    for i in range(1, n):
        for in_col in range(3):
            if in_col == 1:
                j, k = 0, 2
            elif in_col == 0:
                j, k = 1, 2
            else:
                j, k = 0, 1
            current_max = max(dp[i-1][j], dp[i-1][k])
            dp[i][in_col] = current_max + arr[i][in_col]
    return max(dp[-1][0], dp[-1][1], dp[-1][2])

def main():
    n = int(input())
    arr = []
    for _ in range(n):
        a, b, c = map(int, input().split())
        arr.append([a, b, c])
    ans = dpx(arr, n)
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
