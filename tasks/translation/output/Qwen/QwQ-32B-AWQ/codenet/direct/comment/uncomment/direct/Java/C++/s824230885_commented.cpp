#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> list(N);
    for(int i = 0; i < N; i++) {
        cin >> list[i];
    }
    int max_val = 0;
    int output = 0;
    for(int i = 0; i < N; i++) {
        if(max_val <= list[i]) {
            max_val = list[i];
            output++;
        }
    }
    cout << output << endl;
} // End of Code
