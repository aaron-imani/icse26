def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    arr = [[0]*3 for _ in range(n)]
    
    index = 1
    for i in range(n):
        for j in range(3):
            arr[i][j] = int(data[index])
            index += 1
    
    ans = dpx(arr, n)
    print(ans)

def min_func(arr, n):
    if n == 1:
        return 0
    if n == 2:
        return abs(arr[n-1] - arr[n-2])
    op1 = abs(arr[n-1] - arr[n-2]) + min_func(arr, n-1)
    op2 = abs(arr[n-1] - arr[n-3]) + min_func(arr, n-2)
    res = min(op1, op2)
    return res

def dpc(arr, i, n, row):
    if row == n:
        return 0
    j, k = 0, 0
    if i == 1:
        j, k = 0, 2
    elif i == 0:
        j, k = 1, 2
    else:
        j, k = 0, 1
    return arr[row][i] + max(dpc(arr, j, n, row+1), dpc(arr, k, n, row+1))

def dpx(arr, n):
    dp = [[0]*3 for _ in range(n)]
    
    dp[0][0] = arr[0][0]
    dp[0][1] = arr[0][1]
    dp[0][2] = arr[0][2]
    
    for i in range(1, n):
        for in_ in range(3):
            j, k = 0, 0
            if in_ == 1:
                j, k = 0, 2
            elif in_ == 0:
                j, k = 1, 2
            else:
                j, k = 0, 1
            dp[i][in_] = max(dp[i-1][k], dp[i-1][j]) + arr[i][in_]
    
    return max(dp[n-1][0], dp[n-1][1], dp[n-1][2])

if __name__ == "__main__":
    main()
# End of Code
