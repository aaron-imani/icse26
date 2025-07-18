#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string line;
    getline(cin, line);
    vector<int> list;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        list.push_back(num);
    }
    int max_val = 0, count = 0;
    for (int i = 0; i < N; i++) {
        if (list[i] >= max_val) {
            max_val = list[i];
            count++;
        }
    }
    cout << count << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
