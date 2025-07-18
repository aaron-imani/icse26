#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class InputReader {
private:
    istream& stream;
    string buffer;
    vector<string> tokens;

public:
    InputReader(istream& _stream) : stream(_stream) {}

    bool next() {
        if (!tokens.empty()) return true;
        string line;
        while (getline(stream, line) && line.empty());
        stringstream ss(line);
        string token;
        while (ss >> token) tokens.push_back(token);
        return !tokens.empty();
    }

    string nextString() {
        if (!next()) return "";
        string token = tokens.front();
        tokens.erase(tokens.begin());
        return token;
    }

    int nextInt() {
        return stoi(nextString());
    }

    long long nextLong() {
        return stoll(nextString());
    }

    double nextDouble() {
        return stod(nextString());
    }
};

void solve(InputReader& sc, ostream& out) {
    int t = 1;
    while (t--) {
        long long n = sc.nextLong();
        long long m = sc.nextLong();
        if (n == 0) {
            out << 0 << endl;
            continue;
        }
        if (n == m) {
            out << 0 << endl;
            continue;
        }
        if (n > m) {
            n = m + n % m;
            n -= m;
            out << min(m - n, n) << endl;
            continue;
        }
        out << min(m - n, n) << endl;
    }
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
    for (auto& i : arr) i = sc.nextLong();
}

void feedArr(vector<double>& arr, InputReader& sc) {
    for (auto& i : arr) i = sc.nextDouble();
}

void feedArr(vector<int>& arr, InputReader& sc) {
    for (auto& i : arr) i = sc.nextInt();
}

void feedArr(vector<string>& arr, InputReader& sc) {
    for (auto& i : arr) i = sc.nextString();
}

string printArr(const vector<int>& arr) {
    stringstream sbr;
    for (int i : arr) sbr << i << " ";
    return sbr.str();
}

string printArr(const vector<long long>& arr) {
    stringstream sbr;
    for (long long i : arr) sbr << i << " ";
    return sbr.str();
}

string printArr(const vector<string>& arr) {
    stringstream sbr;
    for (const string& i : arr) sbr << i << " ";
    return sbr.str();
}

string printArr(const vector<double>& arr) {
    stringstream sbr;
    for (double i : arr) sbr << i << " ";
    return sbr.str();
}

int main() {
    InputReader in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
