#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class InputReader {
public:
    InputReader(istream& stream) : reader(stream) {}

    string next() {
        while (tokenizer == nullptr || !tokenizer->hasMoreTokens()) {
            string line;
            if (!getline(reader, line)) {
                throw runtime_error("Unexpected end of input");
            }
            tokenizer = make_unique<StringTokenizer>(line);
        }
        return tokenizer->nextToken();
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

private:
    istream& reader;
    unique_ptr<StringTokenizer> tokenizer;

    class StringTokenizer {
    public:
        StringTokenizer(const string& line) : tokens(line), pos(0) {
            stringstream ss(line);
            string token;
            while (ss >> token) {
                tokens.push_back(token);
            }
        }

        bool hasMoreTokens() {
            return pos < tokens.size();
        }

        string nextToken() {
            if (!hasMoreTokens()) {
                throw runtime_error("No more tokens");
            }
            return tokens[pos++];
        }

    private:
        vector<string> tokens;
        size_t pos;
    };
};

class Pair {
public:
    int u, v, i, val;
    Pair(int a, int b, int i) : u(a), v(b), i(i) {}
};

int L, R, top, bottom;

void solve(InputReader& sc, ostream& pw) {
    int t = 1;
    while (t--) {
        long long n = sc.nextLong();
        long long m = sc.nextLong();
        if (n == 0) {
            pw << 0 << endl;
            continue;
        }
        if (n == m) {
            pw << 0 << endl;
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            pw << min(m - n, n) << endl;
            continue;
        }
        pw << min(m - n, n) << endl;
    }
}

void swap(char* chrr, int i, int j) {
    char temp = chrr[i];
    chrr[i] = chrr[j];
    chrr[j] = temp;
}

int num(int n) {
    int a = 0;
    while (n > 0) {
        a += (n & 1);
        n >>= 1;
    }
    return a;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long fast_pow(long long base, long long n, long long M) {
    if (n == 0) return 1;
    if (n == 1) return base;
    long long halfn = fast_pow(base, n / 2, M);
    if (n % 2 == 0) return (halfn * halfn) % M;
    else return (((halfn * halfn) % M) * base) % M;
}

long long modInverse(long long n, long long M) {
    return fast_pow(n, M - 2, M);
}

void feedArr(vector<long long>& arr, InputReader& sc) {
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = sc.nextLong();
    }
}

void feedArr(vector<double>& arr, InputReader& sc) {
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = sc.nextDouble();
    }
}

void feedArr(vector<int>& arr, InputReader& sc) {
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = sc.nextInt();
    }
}

void feedArr(vector<string>& arr, InputReader& sc) {
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = sc.next();
    }
}

string printArr(const vector<int>& arr) {
    stringstream sbr;
    for (int i : arr) {
        sbr << i << " ";
    }
    return sbr.str();
}

string printArr(const vector<long long>& arr) {
    stringstream sbr;
    for (long long i : arr) {
        sbr << i << " ";
    }
    return sbr.str();
}

string printArr(const vector<string>& arr) {
    stringstream sbr;
    for (const string& i : arr) {
        sbr << i << " ";
    }
    return sbr.str();
}

string printArr(const vector<double>& arr) {
    stringstream sbr;
    for (double i : arr) {
        sbr << i << " ";
    }
    return sbr.str();
}

int main() {
    InputReader in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
