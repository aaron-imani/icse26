#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class InputIterator {
    vector<string> inputLine;
    int index = 0;
    int max;
    string read;
public:
    InputIterator() {
        string line;
        while (getline(cin, line)) {
            inputLine.push_back(line);
        }
        max = inputLine.size();
    }

    bool hasNext() { return (index < max); }

    string next() {
        if (hasNext()) {
            return inputLine[index++];
        } else {
            throw out_of_range("There is no more input");
        }
    }
};

InputIterator ii; // This class cannot be used in reactive problem.
void flush() { cout.flush(); }
void myout(const auto& t) { cout << t << endl; }
void myerr(const auto& t) { cerr << "debug:" << t << endl; }
string next() { return ii.next(); }
bool hasNext() { return ii.hasNext(); }
int nextInt() { return stoi(next()); }
long long nextLong() { return stoll(next()); }
double nextDouble() { return stod(next()); }

vector<string> nextStrArray() { return myconv(next(), 8); }
vector<string> nextCharArray() { return myconv(next(), 0); }

vector<int> nextIntArray() {
    vector<string> input = nextStrArray();
    vector<int> ret(input.size());
    for (int i = 0; i < input.size(); i++) {
        ret[i] = stoi(input[i]);
    }
    return ret;
}

vector<long long> nextLongArray() {
    vector<string> input = nextStrArray();
    vector<long long> ret(input.size());
    for (int i = 0; i < input.size(); i++) {
        ret[i] = stoll(input[i]);
    }
    return ret;
}

string myconv(const auto& list, int no) { // only join
    string joinString;
    if (no == 8) joinString = " ";
    else if (no == 0) joinString = "";
    else throw invalid_argument("Invalid conversion type");

    if constexpr (is_same_v<decltype(list), vector<string>>) {
        return join(list, joinString);
    } else {
        throw invalid_argument("Don't join");
    }
}

vector<string> myconv(const string& str, int no) { // only split
    string splitString;
    if (no == 8) splitString = " ";
    else if (no == 0) splitString = "";
    else throw invalid_argument("Invalid conversion type");

    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, splitString[0])) {
        result.push_back(item);
    }
    return result;
}

string join(const vector<string>& v, const string& delimiter) {
    string result;
    for (size_t i = 0; i < v.size(); ++i) {
        result += v[i];
        if (i != v.size() - 1) {
            result += delimiter;
        }
    }
    return result;
}

void solve() { // Here is the main function
    int N = nextInt();
    vector<int> list = nextIntArray();
    int max = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (max <= list[i]) {
            max = list[i];
            output++;
        }
    }
    myout(output);
}

int main() {
    solve();
    flush();
    return 0;
}
// End of Code
