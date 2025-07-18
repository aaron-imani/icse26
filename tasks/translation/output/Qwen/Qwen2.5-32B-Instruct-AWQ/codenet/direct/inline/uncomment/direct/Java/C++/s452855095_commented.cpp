#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int cnt = 0;
    bool flag = true;
    while (true) {
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 != 0) {
                flag = false;
                break;
            } else {
                arr[i] /= 2;
            }
        }
        if (flag == true) {
            cnt++;
        } else {
            break;
        }
    }
    std::cout << cnt << std::endl;

    return 0; // End of Code
}
