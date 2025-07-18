def min_func(arr, n):
    if n == 1:
        return 0
    if n == 2:
        return abs(arr[n-1] - arr[n-2])
    op1 = abs(arr[n-1] - arr[n-2]) + min_func(arr, n-1)
    op2 = abs(arr[n-1] - arr[n-3]) + min_func(arr, n-2)
    return min(op1, op2)

ndef dpc(arr, i, n, row):
    if row == n:
        return 0
    j, k = 0, 0
    if i == 1:
        j = 0
        k = 2
    elif i == 0:
        j = 1
        k = 2
    else:
        j = 0
        k = 1
    return arr[row][i] + max(dpc(arr, j, n, row + 1), dpc(arr, k, n, row + 1))

ndef dpx(arr, n):
    dp = [[0]*3 for _ in range(n)]
    dp[0][0] = arr[0][0]
    dp[0][1] = arr[0][1]
    dp[0][2] = arr[0][2]
    for i in range(1, n):
        for in_col in range(3):
            j, k = 0, 0
            if in_col == 1:
                j = 0
                k = 2
            elif in_col == 0:
                j = 1
                k = 2
            else:
                j = 0
                k = 1
            dp[i][in_col] = max(dp[i-1][j], dp[i-1][k]) + arr[i][in_col]
    return max(dp[-1])

nimport sys
n = int(sys.stdin.readline())
arr = []
for _ in range(n):
    a, b, c = map(int, sys.stdin.readline().split())
    arr.append([a, b, c])
ans = dpx(arr, n)
print(ans)
#End of Code
