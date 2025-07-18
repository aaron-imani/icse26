#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class FastReader {
public:
    FastReader() {}

    string next() {
        while (!st.hasMoreTokens()) {
            try {
                st = stringstream(br.readLine());
            } catch (exception &e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return stoi(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    double nextDouble() {
        return stod(next());
    }

    string nextLine() {
        string str = "";
        try {
            str = br.readLine();
        } catch (exception &e) {
            e.printStackTrace();
        }
        return str;
    }

private:
    istringstream st;
    string br;
};

int main() {
    FastReader s;
    int n = s.nextInt();
    int m = s.nextInt();

    vector<int> penal(n + 1, 0);
    vector<bool> solved(n + 1, false);

    for (int i = 0; i < m; i++) {
        int num = s.nextInt();
        string str = s.next();
        if (str[0] == 'A') {
            solved[num] = true;
        } else {
            if (!solved[num]) {
                penal[num]++;
            }
        }
    }

    int correct_ans = 0;
    int num_penal = 0;
    for (int i = 1; i <= n; i++) {
        if (solved[i]) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    cout << correct_ans << " " << num_penal << "\n";

    return 0;
}

// End of Code
