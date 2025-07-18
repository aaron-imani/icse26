#include <stdio.h>

// Function to read an integer from standard input
int readInt() {
    int ret = 0;
    char c = getchar();
    int sign = 1;

    // Handle negative sign
    if (c == '-') {
        sign = -1;
        c = getchar();
    }

    // Read digits and convert to integer
    while (c >= '0' && c <= '9') {
        ret = ret * 10 + c - '0';
        c = getchar();
    }

    return ret * sign;
}

int main() {
    int K = readInt();
    int S = readInt();
    int ans = 0;

    // Iterate over possible values of x and y
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            int z = S - x - y; // Calculate z based on the equation X + Y + Z = S
            if (z >= 0 && z <= K) { // Check if z is within the valid range
                ans++;
            }
        }
    }

    // Output the result
    printf("%d\n", ans);
    return 0;
}
// End of Code
