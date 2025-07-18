#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int max_num, min_num;
    cin >> max_num;
    min_num = max_num;
    for(int i = 1; i < N; i++) {
        int current;
        cin >> current;
        max_num = max(max_num, current);
        min_num = min(min_num, current);
    }
    cout << (max_num - min_num) << endl;
    return 0;
} // End of Code
