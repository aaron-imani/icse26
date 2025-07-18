#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class InputIterator {
private:
    vector<string> inputLine;
    int index = 0;
    string read;
public:
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

int nextInt() {
    return stoi(InputIterator().next());
}

vector<int> nextIntArray() {
    string line = InputIterator().next();
    stringstream ss(line);
    vector<int> ret;
    int temp;
    while(ss >> temp) {
        ret.push_back(temp);
    }
    return ret;
}

void solve() {
    int N = nextInt();
    vector<int> list = nextIntArray();
    int max = 0;
    int output = 0;
    for(int i = 0; i < N; i++) {
        if(max <= list[i]) {
            max = list[i];
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
