#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int max, min;
    cin >> max;
    min = max;
    for(int i=1; i<N; i++) {
        int in;
        cin >> in;
        max = max(max, in);
        min = min(min, in);
    }
    cout << (max - min) << endl;
    return 0;
}
// End of Code
