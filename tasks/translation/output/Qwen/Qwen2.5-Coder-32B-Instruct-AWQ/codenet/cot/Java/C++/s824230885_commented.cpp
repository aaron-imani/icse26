#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <limits>

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

map<int, string> CONVSTR;
InputIterator ii; // This class cannot be used in reactive problem.
void flush() { cout.flush(); }
void myout(const string& t) { cout << t << endl; }
void myerr(const string& t) { cerr << "debug:" << t << endl; }
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
    for (size_t i = 0; i < input.size(); i++) {
        ret[i] = stoi(input[i]);
    }
    return ret;
}
vector<long long> nextLongArray() {
    vector<string> input = nextStrArray();
    vector<long long> ret(input.size());
    for (size_t i = 0; i < input.size(); i++) {
        ret[i] = stoll(input[i]);
    }
    return ret;
}
string myconv(const vector<string>& list, int no) { // only join
    string joinString = CONVSTR[no];
    string result;
    for (size_t i = 0; i < list.size(); i++) {
        result += list[i];
        if (i != list.size() - 1) {
            result += joinString;
        }
    }
    return result;
}
vector<string> myconv(const string& str, int no) { // only split
    string splitString = CONVSTR[no];
    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, splitString[0])) {
        result.push_back(item);
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
    myout(to_string(output));
}

int main() {
    CONVSTR[8] = " ";
    CONVSTR[9] = "\n";
    CONVSTR[0] = "";
    solve();
    flush();
    return 0;
}
// End of Code
