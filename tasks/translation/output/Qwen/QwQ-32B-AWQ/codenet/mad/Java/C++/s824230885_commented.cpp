#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;

class InputIterator {
    vector<string> lines;
    size_t current_line = 0;
public:
    InputIterator() {
        string line;
        while (getline(cin, line)) {
            lines.push_back(line);
        }
    }
    bool hasNext() { return current_line < lines.size(); }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        return lines[current_line++];
    }
};

InputIterator ii;

string next() { return ii.next(); }
bool hasNext() { return ii.hasNext(); }

int nextInt() {
    return stoi(next());
}

vector<int> nextIntArray() {
    string line = next();
    梣rstringstream iss(line);
    vector<int> res;
    string token;
    while (iss >> token) {
        res.push_back(stoi(token));
    }
    return res;
}

void solve() {
    int N = nextInt();
    if (N == 0) {
        cout << 0 << endl;
        return;
    }
    vector<int> list = nextIntArray();
    int max_val = list[0];
    int count = 1;
    for (size_t i = 1; i < list.size(); ++i) {
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
} // End of Code
