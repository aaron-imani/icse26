#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int firstVal;
    cin >> firstVal;
    int max = firstVal, min = firstVal;
    for(int i = 1; i < N; i++) {
        int in;
        cin >> in;
        max = std::max(max, in);
        min = std::min(min, in);
    }
    cout << (max - min) << endl;
    return 0;
} // End of Code
