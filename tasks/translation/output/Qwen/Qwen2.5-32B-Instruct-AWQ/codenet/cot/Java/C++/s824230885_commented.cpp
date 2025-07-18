#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

namespace Main {
    class InputIterator {
        vector<string> inputLine;
        int index = 0, max;
        string read;
    public:
        InputIterator() {
            while (getline(cin, read)) {
                inputLine.push_back(read);
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
    InputIterator ii;
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
    string myconv(const string& list, int no) {
        string joinString = CONVSTR[no];
        if (list.find(joinString) != string::npos) {
            return list;
        } else {
            throw invalid_argument("Don't join");
        }
    }
    vector<string> myconv(const string& str, int no) {
        string splitString = CONVSTR[no];
        vector<string> ret;
        stringstream ss(str);
        string item;
        while (getline(ss, item, splitString[0])) {
            ret.push_back(item);
        }
        return ret;
    }
    void solve() {
        CONVSTR[8] = " ";
        CONVSTR[9] = "\n";
        CONVSTR[0] = "";
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
}

int main() {
    Main::solve();
    Main::flush();
    return 0;
} // End of Code
