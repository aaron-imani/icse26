#include <iostream>
#include <vector>
#include <string>

int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::string s;
    std::cin >> s;
    std::vector<int> pre(N + 1, 0);
    for (int i = 1; i < N; i++) {
        if (s[i - 1] == 'A' && s[i] == 'C') {
            pre[i] = 1; // initially the prefix sum array is the k array
        }
    }
    // Building the psa
    for (int i = 1; i < N; i++) {
        pre[i] += pre[i - 1];
    }
    // Querying
    while (Q-- > 0) {
        int l, r;
        std::cin >> l >> r;
        r--;
        std::cout << pre[r] - pre[l - 1] << std::endl;
    }
}
// End of Code
