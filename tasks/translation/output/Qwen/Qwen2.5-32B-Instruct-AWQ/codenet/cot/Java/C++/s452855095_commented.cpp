#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr;
    int n, cnt = 0;
    std::cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++)
        std::cin >> arr[i];
    bool flag = true;
    while(true) {
        for(int i = 0; i < n; i++) {
            if(arr[i] % 2 != 0) {
                flag = false;
                break;
            } else {
                arr[i] = arr[i] / 2;
            }
        }
        if(flag == true)
            cnt++;
        else
            break;
    }
    std::cout << cnt << std::endl;
    // End of Code
}
