#include <stdio.h>

int min(int arr[], int n) { 
    if (n == 1) return 0;
    if (n == 2) return abs(arr[n-1] - arr[n-2]);
    int op1 = abs(arr[n-1] - arr[n-2]) + min(arr, n-1);
    int op2 = abs(arr[n-1] - arr[n-3]) + min(arr, n-2);
    int res = op1 < op2 ? op1 : op2;
    return res;
}

int dpc(int arr[][3], int i, int n, int row) {
    if (row == n)
        return 0;
    int j = 0, k = 0;
    if (i == 1) {
        j = 0;
        k = 2;
    } else if (i == 0) {
        j = 1;
        k = 2;
    } else {
        j = 0;
        k = 1;
    }
    return arr[row][i] + (dpc(arr, j, n, row+1) > dpc(arr, k, n, row+1) ? dpc(arr, j, n, row+1) : dpc(arr, k, n, row+1));
}

int dpx(int arr[][3], int n) {
    int dp[n][3];
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for (int i = 1; i < n; i++) {
        for (int in = 0; in < 3; in++) {
            int j = 0, k = 0;
            if (in == 1) {
                j = 0;
                k = 2;
            } else if (in == 0) {
                j = 1;
                k = 2;
            } else {
                j = 0;
                k = 1;
            }
            dp[i][in] = (dp[i-1][k] > dp[i-1][j] ? dp[i-1][k] : dp[i-1][j]) + arr[i][in];
        }
    }
    return dp[n-1][0] > dp[n-1][1] ? (dp[n-1][0] > dp[n-1][2] ? dp[n-1][0] : dp[n-1][2]) : (dp[n-1][1] > dp[n-1][2] ? dp[n-1][1] : dp[n-1][2]);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int ans = dpx(arr, n);
    printf("%d\n", ans);
    return 0;
}
// End of Code
