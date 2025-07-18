#include <iostream>
#include <vector>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int cnt = 0;
    bool flag = true;
    while (true) {
        flag = true;
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 2 != 0) {
                flag = false;
                break;
            } else {
                arr[i] /= 2;
            }
        }
        if (flag) {
            cnt++;
        } else {
            break;
        }
    }
    std::cout << cnt;
    return 0;
}
// End of Code
