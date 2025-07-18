#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<string> inputLines;
int index = 0;

string next() {
    if (index < inputLines.size()) {
        return inputLines[index++];
    }
    throw runtime_error("No more input");
}

int nextInt() {
    return stoi(next());
}

vector<int> nextIntArray() {
    string line = next();
    vector<int> arr;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

void solve() {
    int N = nextInt();
    vector<int> list = nextIntArray();
    int max_val = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (list[i] >= max_val) {
            max_val = list[i];
            output++;
        }
    }
    cout << output << endl;
}

int main() {
    string line;
    vector<string> localInputLines;
    while (getline(cin, line)) {
        localInputLines.push_back(line);
    }
    inputLines = localInputLines;
    index = 0;
    solve();
    return 0;
}
// End of Code
