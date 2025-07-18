#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];
    
    int cnt = 0;
    bool flag = true;
    while(flag) {
        flag = false;
        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 != 0) {
                flag = true;
                break;
            } else {
                arr[i] /= 2;
            }
        }
        if(!flag)
            cnt++;
    }
    std::cout << cnt;
    return 0;
}
// End of Code
