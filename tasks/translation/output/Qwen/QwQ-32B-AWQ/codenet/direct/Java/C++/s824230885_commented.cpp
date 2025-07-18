#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct InputIterator {
    vector<string> inputLine;
    size_t index = 0;
    InputIterator() {
        string line;
        while (getline(cin, line)) {
            inputLine.push_back(line);
        }
    }
    bool hasNext() const { return index < inputLine.size(); }
    string next() {
        if (hasNext()) {
            return inputLine[index++];
        } else {
            throw runtime_error("No more input");
        }
    }
};

InputIterator ii;

string next() {
    return ii.next();
}

bool hasNext() {
    return ii.hasNext();
}

int nextInt() {
    string s = next();
    return stoi(s);
}

vector<string> nextStrArray() {
    string s = next();
    vector<string> result;
    stringstream ss(s);
    string token;
    while (getline(ss, token, ' ')) {
        result.push_back(token);
    }
    return result;
}

vector<int> nextIntArray() {
    vector<string> tokens = nextStrArray();
    vector<int> result;
    for (const string& s : tokens) {
        result.push_back(stoi(s));
    }
    return result;
}

void solve() {
    int N = nextInt();
    vector<int> list = nextIntArray();
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; ++i) {
        if (max <= list[i]) {
            max = list[i];
            ++output;
        }
    }
    cout << output << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
