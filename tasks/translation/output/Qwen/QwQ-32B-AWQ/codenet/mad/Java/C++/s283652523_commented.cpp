#include <iostream>
#include <vector>
using namespace std;

class FastScanner {
private:
    istream& in;
public:
    FastScanner(istream& input = cin) : in(input) {}
    
    int nextInt() {
        long long nl = nextLong();
        if (nl < INT_MIN || nl > INT_MAX) {
            throw runtime_error("Number out of int range");
        }
        return static_cast<int>(nl);
    }
    
    long long nextLong() {
        long long sign = 1;
        char c;
        do {
            c = in.get();
        } while ( (c < '0' || c > '9') && c != '-' && c != '+' && c != EOF );
        
        if (c == '-') {
            sign = -1;
            c = in.get();
        } else if (c == '+') {
            c = in.get();
        }
        
        if (c == EOF) {
            return -1;
        }
        
        long long ret = 0;
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + (c - '0');
            c = in.get();
        }
        return ret * sign;
    }
    
    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = nextInt();
        }
        return res;
    }
};

const int MOD = 1000000007;

void solve(FastScanner& in, ostream& out) {
    int N = in.nextInt();
    vector<int> A = in.nextIntArray(N);
    
    long long ans = 0;
    long long sum = A.back();
    for (int i = N-2; i >=0; --i) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    out << ans << endl;
}

int main() {
    FastScanner scanner;
    solve(scanner, cout);
    return 0;
}
// End of Code
