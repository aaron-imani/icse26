#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<int> v(N + 1);
    std::vector<int> w(N + 1);

    for (int i = 1; i <= N; i++) {
        std::cin >> v[i] >> w[i];
    }

    std::vector<std::vector<int>> sumV(N + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum <= W; i_sum++) {
            if (i_sum < w[i]) {
                sumV[i][i_sum] = sumV[i - 1][i_sum];
            } else {
                sumV[i][i_sum] = std::max(sumV[i - 1][i_sum], sumV[i - 1][i_sum - w[i]] + v[i]);
            }
        }
    }

    std::cout << sumV[N][W] << std::endl;
}

// End of Code
