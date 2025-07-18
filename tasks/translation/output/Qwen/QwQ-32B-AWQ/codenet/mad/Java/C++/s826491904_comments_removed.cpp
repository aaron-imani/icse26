#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int max_val, min_val;
    cin >> max_val;
    min_val = max_val;
    for(int i = 1; i < N; ++i) {
        int num;
        cin >> num;
        max_val = max(max_val, num);
        min_val = min(min_val, num);
    }
    cout << (max_val - min_val) << endl;
    return 0;
} // End of Code
