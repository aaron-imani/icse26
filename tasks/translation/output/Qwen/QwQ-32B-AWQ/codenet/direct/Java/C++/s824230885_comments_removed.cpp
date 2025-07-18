#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> inputLines;
int lineIndex = 0;

string nextLine() {
    if (lineIndex >= inputLines.size()) throw runtime_error("No more input");
    return inputLines[lineIndex++];
}

int nextInt() {
    return stoi(nextLine());
}

vector<int> nextIntArray() {
    string line = nextLine();
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    vector<int> ret;
    for (const string& s : tokens) {
        ret.push_back(stoi(s));
    }
    return ret;
}

void solve() {
    int N = nextInt();
    vector<int> list = nextIntArray();
    int maxVal = 0;
    int output = 0;
    for (int i = 0; i < N; ++i) {
        if (maxVal <= list[i]) {
            maxVal = list[i];
            output++;
        }
    }
    cout << output << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    while (getline(cin, line)) {
        inputLines.push_back(line);
    }
    solve();
    return 0;
}
// End of Code
