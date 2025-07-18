#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int max_val, min_val;
    cin >> max_val;
    min_val = max_val;
    for(int i = 1; i < N; i++){
        int in;
        cin >> in;
        max_val = max(max_val, in);
        min_val = min(min_val, in);
    }
    cout << max_val - min_val << endl;
    return 0; // End of Code
}
