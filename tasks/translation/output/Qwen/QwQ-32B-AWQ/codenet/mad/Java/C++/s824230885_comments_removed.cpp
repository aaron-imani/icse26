#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<string> inputLines;
int currentLine = 0;

string next() {
    if (currentLine < inputLines.size()) {
        return inputLines[currentLine++];
    }
    throw runtime_error("No more input");
}

bool hasNext() {
    return currentLine < inputLines.size();
}

int nextInt() {
    return stoi(next());
}

vector<int> nextIntArray() {
    string line = next();
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

void solve() {
    int N = nextInt();
    vector<int> list = nextIntArray();
    if (N == 0) {
        cout << 0 << endl;
        return;
    }
    int max = list[0];
    int output = 1;
    for (int i = 1; i < N; ++i) {
        if (list[i] > max) {
            max = list[i];
            ++output;
        }
    }
    cout << output << endl;
}

int main() {
    inputLines.clear();
    currentLine = 0;
    string line;
    while (getline(cin, line)) {
        inputLines.push_back(line);
    }
    solve();
    cout.flush();
    return 0; // End of Code
}
