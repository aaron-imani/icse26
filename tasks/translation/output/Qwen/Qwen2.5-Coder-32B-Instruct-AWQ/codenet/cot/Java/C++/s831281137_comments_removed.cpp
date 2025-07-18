#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v, w;
int N, W;

int main() {
    std::cin >> N >> W;
    v.resize(N + 1);
    w.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        std::cin >> v[i] >> w[i];
    }

    std::vector<std::vector<int>> sumV(N + 1, std::vector<int>(W + 1));

    for (int i = 1; i <= N; i++) {
        for (int i_sum = 0; i_sum < w[i]; i_sum++) {
            sumV[i][i_sum] = sumV[i - 1][i_sum];
        }

        for (int i_sum = w[i]; i_sum <= W; i_sum++) {
            sumV[i][i_sum] = std::max(sumV[i - 1][i_sum], sumV[i - 1][i_sum - w[i]] + v[i]);
        }
    }

    std::cout << sumV[N][W] << std::endl;
    return 0;
}
// End of Code
