#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class InputIterator {
public:
    vector<string> inputLine;
    int index = 0;
    string read;

    InputIterator() {
        string line;
        while(getline(cin, line)) {
            inputLine.push_back(line);
        }
    }

    bool hasNext() { return (index < inputLine.size()); }
    string next() {
        if(hasNext()) {
            return inputLine[index++];
        } else {
            throw out_of_range("There is no more input");
        }
    }
};

InputIterator ii;
ostream& out = cout;

void flush() { out.flush(); }
void myout(const auto& t) { out << t << endl; }
void myerr(const auto& t) { cerr << "debug:" << t << endl; }
string next() { return ii.next(); }
bool hasNext() { return ii.hasNext(); }
int nextInt() { return stoi(next()); }
long long nextLong() { return stoll(next()); }
double nextDouble() { return stod(next()); }
vector<string> nextStrArray() { return split(next(), ' '); }
vector<string> nextCharArray() { return split(next(), '\0'); }
vector<int> nextIntArray() {
    vector<string> input = nextStrArray();
    vector<int> ret;
    for(const auto& s : input) {
        ret.push_back(stoi(s));
    }
    return ret;
}
vector<long long> nextLongArray() {
    vector<string> input = nextStrArray();
    vector<long long> ret;
    for(const auto& s : input) {
        ret.push_back(stoll(s));
    }
    return ret;
}

vector<string> split(const string& str, char delimiter) {
    stringstream ss(str);
    string token;
    vector<string> tokens;
    while(getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void solve() {
    int N = nextInt();
    vector<int> list = nextIntArray();
    int maxVal = 0;
    int output = 0;
    for(int i = 0; i < N; i++) {
        if(maxVal <= list[i]) {
            maxVal = list[i];
            output++;
        }
    }
    myout(output);
}

int main() {
    solve();
    flush();
} // End of Code
