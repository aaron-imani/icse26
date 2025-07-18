#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class FastScanner {
private:
    istream* input;

public:
    FastScanner(istream& stream) : input(&stream) {}
    FastScanner() : input(&cin) {}

    ~FastScanner() {
        if (input != &cin) {
            delete input;
        }
    }

    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) throw runtime_error("Overflow");
        return static_cast<int>(nl);
    }

    long long nextLong() {
        int sign = 1;
        int b = input->get();
        while ((b < '0' || '9' < b) && b != '-' && b != '+') {
            b = input->get();
        }
        if (b == '-') {
            sign = -1;
            b = input->get();
        } else if (b == '+') {
            b = input->get();
        }
        long long ret = b - '0';
        while (true) {
            b = input->get();
            if (b < '0' || '9' < b) return ret * sign;
            ret *= 10;
            ret += b - '0';
        }
    }

    double nextDouble() {
        int sign = 1;
        int b = input->get();
        while ((b < '0' || '9' < b) && b != '-' && b != '+') {
            b = input->get();
        }
        if (b == '-') {
            sign = -1;
            b = input->get();
        } else if (b == '+') {
            b = input->get();
        }
        double ret = b - '0';
        while (true) {
            b = input->get();
            if (b < '0' || '9' < b) break;
            ret *= 10;
            ret += b - '0';
        }
        if (b != '.') return sign * ret;
        double div = 1;
        b = input->get();
        while ('0' <= b && b <= '9') {
            ret *= 10;
            ret += b - '0';
            div *= 10;
            b = input->get();
        }
        return sign * ret / div;
    }

    char nextChar() {
        int b = input->get();
        while (isspace(b)) {
            b = input->get();
        }
        return static_cast<char>(b);
    }

    string nextStr() {
        string sb;
        int b = input->get();
        while (isspace(b)) {
            b = input->get();
        }
        while (b != -1 && !isspace(b)) {
            sb.push_back(static_cast<char>(b));
            b = input->get();
        }
        return sb;
    }

    string nextLine() {
        string sb;
        int b = input->get();
        while (b != -1 && b != '\n') {
            sb.push_back(static_cast<char>(b));
            b = input->get();
        }
        return sb;
    }

    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextInt();
        }
        return res;
    }

    vector<long long> nextLongArray(int n) {
        vector<long long> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = nextLong();
        }
        return res;
    }
};

const int MOD = 1e9 + 7;

void solve(FastScanner& in, ostream& out) {
    int N = in.nextInt();
    vector<int> A = in.nextIntArray(N);

    long long ans = 0, sum = A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    out << ans << endl;
}

int main() {
    FastScanner in(cin);
    ostream& out = cout;
    // Uncomment below lines to use file input/output
    // ifstream inputFile("input.txt");
    // ofstream outputFile("output.txt");
    // if (!inputFile.is_open()) {
    //     cerr << "Failed to open input file" << endl;
    //     return 1;
    // }
    // if (!outputFile.is_open()) {
    //     cerr << "Failed to open output file" << endl;
    //     return 1;
    // }
    // FastScanner in(inputFile);
    // ostream& out = outputFile;

    solve(in, out);
    return 0;
} // End of Code
