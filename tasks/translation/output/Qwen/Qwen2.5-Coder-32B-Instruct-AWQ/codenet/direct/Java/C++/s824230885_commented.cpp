#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

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
vector<string> myconv(const string& str, const string& delimiter) {
    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, delimiter[0])) {
        result.push_back(item);
    }
    return result;
}

void solve() {
    int N = stoi(ii.next());
    vector<int> list;
    string line = ii.next();
    vector<string> strList = myconv(line, " ");
    for (const string& s : strList) {
        list.push_back(stoi(s));
    }
    int maxVal = 0;
    int output = 0;
    for (int i = 0; i < N; i++) {
        if (maxVal <= list[i]) {
            maxVal = list[i];
            output++;
        }
    }
    cout << output << endl;
}

int main() {
    solve();
    return 0;
}
// End of Code
