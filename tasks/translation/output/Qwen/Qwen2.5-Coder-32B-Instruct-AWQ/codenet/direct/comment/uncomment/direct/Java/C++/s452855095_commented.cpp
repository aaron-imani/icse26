#include <iostream>
#include <vector>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int cnt = 0;
    bool flag = true;
    while (true) {
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                flag = false;
                break;
            } else {
                arr[i] = arr[i] / 2;
            }
        }
        if (flag == true) {
            cnt++;
        } else {
            break;
        }
        flag = true; // Reset flag for the next iteration
    }
    std::cout << cnt;
    return 0;
}
// End of Code
