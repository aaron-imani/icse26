#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    long n, a, b;
    std::cin >> n >> a >> b;

    long sa = std::abs(a - b);

    long ans = 0;

    if (sa % 2 == 0) {
        ans = sa / 2;
    } else {
        long AAA = std::min((n - a), (a - 1));
        long BBB = std::min((n - b), (b - 1));

        ans = std::min(AAA, BBB); // One of them reaches the edge.

        // Decrease the difference by 1 => the difference becomes even
        sa -= 1;
        ans += 1;

        // The difference is now even
        ans += sa / 2;
    }

    std::cout << ans << std::endl;

    //std::cout << 1 / 2 << std::endl;

    return 0;
}

// End of Code
