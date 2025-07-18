#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

class Pair {
public:
    int u, v, i, val;
    Pair(int a, int b, int i) : u(a), v(b), i(i) {}
    // public int compareTo(Pair p){
    //     return (b-p.b);
    // }
    // public int hashCode(){
    //     int hashcode = (a+" "+b).hashCode();
    //     return hashcode;
    // }
    // public boolean equals(Object obj){
    //     if (obj instanceof Pair) {
    //         Pair p = (Pair) obj;
    //         return (p.a==this.a && p.b == this.b);
    //     }
    //     return false;
    // }
};

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

void feedArr(vector<long long>& arr, istream& in) {
    for (auto& i : arr) in >> i;
}

void feedArr(vector<double>& arr, istream& in) {
    for (auto& i : arr) in >> i;
}

void feedArr(vector<int>& arr, istream& in) {
    for (auto& i : arr) in >> i;
}

void feedArr(vector<string>& arr, istream& in) {
    for (auto& i : arr) in >> i;
}

string printArr(const vector<int>& arr) {
    stringstream ss;
    for (const auto& i : arr) ss << i << " ";
    return ss.str();
}

string printArr(const vector<long long>& arr) {
    stringstream ss;
    for (const auto& i : arr) ss << i << " ";
    return ss.str();
}

string printArr(const vector<string>& arr) {
    stringstream ss;
    for (const auto& i : arr) ss << i << " ";
    return ss.str();
}

string printArr(const vector<double>& arr) {
    stringstream ss;
    for (const auto& i : arr) ss << i << " ";
    return ss.str();
}

class InputReader {
public:
    istream& reader;
    string buffer;
    vector<string> tokens;
    int tokenIndex;

    InputReader(istream& stream) : reader(stream), tokenIndex(0) {}

    string next() {
        while (tokenIndex >= tokens.size()) {
            getline(reader, buffer);
            tokens.clear();
            stringstream ss(buffer);
            string token;
            while (ss >> token) tokens.push_back(token);
            tokenIndex = 0;
        }
        return tokens[tokenIndex++];
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
};

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

int main() {
    InputReader in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
