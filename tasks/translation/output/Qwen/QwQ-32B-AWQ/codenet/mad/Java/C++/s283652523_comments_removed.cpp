#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

const int MOD = 1000000007;

struct FastScanner {
    istream& is;
    FastScanner(istream& _is) : is(_is) {}
    
    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) {
            throw invalid_argument("Number out of range");
        }
        return static_cast<int>(nl);
    }
    
    long long nextLong() {
        int sign = 1;
        int b = is.get();
        while (true) {
            if ( (b >= '0' && b <= '9') || b == '-' || b == '+' ) break;
            b = is.get();
        }
        
        if (b == '-') {
            sign = -1;
            b = is.get();
        } else if (b == '+') {
            b = is.get();
        }
        
        long long ret = ,:,:0;
        while (true) {
            if (b == EOF || b < '0' || b > '9') break;
            ret = ret * 10 + (b - '0');
            b = is.get();
        }
        return ret * sign;
    }
    
    double nextDouble() {
        int sign = 1;
        int b = is.get();
        while ( (b < '0' || b > '9') && b != '-' && b != '+' ) {
            b = is.get();
        }
        if (b == '-') {
            sign = -1;
            b = is.get();
        } else if (b == '+') {
            b = is.get();
        }
        
        double ret = 0.0;
        while (true) {
            if (b < '0' || b > '9') break;
            ret = ret * 10 + (b - '0');
            b = is.get();
        }
        
        if (b != '.') {
            return sign * ret;
        }
        
        double div = 1.0;
        b = is.get();
        while (b >= '0' && b <= '9') {
            ret = ret * 10 + (b - '0');
            div *= 10;
            b = is.get();
        }
        return sign * ret / div;
    }
    
    char nextChar() {
        int b = is.get();
        while (isspace(b)) {
            b = is.get();
        }
        return static_cast<char>(b);
    }
    
    string nextStr() {
        string sb;
        int b = is.get();
        while (isspace(b)) {
            b = is.get();
        }
        while (b != EOF && !isspace(b)) {
            sb += static_cast<char>(b);
            b = is.get();
        }
        return sb;
    }
    
    string nextLine() {
        string sb;
        int b = is.get();
        while (b != '\n' && b != EOF) {
            sb += static_cast<char>(b);
            b = is.get();
        }
        return sb;
    }
    
    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = nextInt();
        return res;
    }
    
    vector<int> nextIntArrayDec(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = nextInt() -1;
        return res;
    }
    
    vector<int> nextIntArray1Index(int n) {
        vector<int> res(n+1);
        for (int i = 0; i < n; i++) res[i+1] = nextInt();
        return res;
    }
    
    vector<long long> nextLongArray(int n) {
        vector<long long> res(n);
        for (int i = 0; i < n; i++) res[i] = nextLong();
        return res;
    }
    
    vector<long long> nextLongArrayDec(int n) {
        vector<long long> res(n);
        for (int i = 0; i < n; i++) res[i] = nextLong() -1;
        return res;
    }
    
    vector<long long> nextLongArray1Index(int n) {
        vector<long long> res(n+1);
        for (int i = 0; i < n; i++) res[i+1] = nextLong();
        return res;
    }
    
    vector<double> nextDoubleArray(int n) {
        vector<double> res(n);
        for (int i = 0; i < n; i++) res[i] = nextDouble();
        return res;
    }
};

void solve(FastScanner& in, ostream& out) {
    int N = in.nextInt();
    vector<int> A = in.nextIntArray(N);
    
    long long ans = 0, sum = A.back();
    for (int i = N - 2; i >= 0; --i) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    out << ans << endl;
}

int main() {
    FastScanner in(cin);
    solve(in, cout);
    return 0;
}
// End of Code
