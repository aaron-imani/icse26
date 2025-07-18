#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

struct FastReader {
    istream& in;
    deque<string> tokens;
    FastReader(istream& in = cin) : in(in) {}
    
    string next() {
        if (tokens.empty()) {
            string line;
            getline(in, line);
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
        }
        string res = tokens.front();
        tokens.pop_front();
        return res;
    }
    
    int nextInt() {
        return stoi(next());
    }
};

int main() {
    FastReader reader;
    int n = reader.nextInt();
    int m = reader.nextInt();
    
    vector<int> penal(n+1, 0);
    vector<bool> solved(n+1, false);
    
    for (int i = 0; i < m; ++i) {
        int num = reader.nextInt();
        string str = reader.next();
        if (str[0] == 'A') {
            solved[num] = true;
        } else {
            if (!solved[num]) {
                penal[num]++;
            }
        }
    }
    
    int correct_ans = 0, num_penal = 0;
    for (int i = 1; i <= n; ++i) {
        if (solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }
    
    cout << correct_ans << " " << num_penal << endl;
    return 0;
}
// End of Code
