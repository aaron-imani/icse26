#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<string> tokens;
size_t pos = 0;

void read_all_tokens() {
    tokens.clear();
    pos = 0;
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
    }
}

int nextInt() {
    return stoi(tokens[pos++]);
}

void solve() {
    int N = nextInt();
    vector<int> list(N);
    for (int i = 0; i < N; ++i) {
        list[i] = nextInt();
    }
    int max = 0, output = 0;
    for (int x : list) {
        if (x >= max) {
            max = x;
            output++;
        }
    }
    cout << output << endl;
}

int main() {
    read_all_tokens();
    solve();
    return 0;
}
// End of Code
