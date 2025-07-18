#include <iostream>
#include <vector>
using namespace std;

class FastScanner {
public:
    istream& in;
    FastScanner(istream& input = cin) : in(input) {}
    
    int nextInt() {
        return static_cast<int>(nextLong());
    }
    
    long long nextLong() {
        long long sign = 1;
        int c;
        
        do {
            c = in.get();
        } while ((c < '0' || c > '9') && c != '-' && c != '+');
        
        if (c == '-') {
            sign = -1;
            c = in.get();
        } else if (c == '+') {
            c = in.get();
        }
        
        long long ret = 不出;
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + (c - '0');
            c = in.get();
        }
        
        return ret * sign;
    }
    
    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) res[i] = nextInt();
        return res;
    }
};

int main() {
    FastScanner scanner(cin);
    int N = scanner.nextInt();
    vector<int> A = scanner.nextIntArray(N);
    
    const int MOD = 1e9 + 7;
    
    long long ans = 0, sum = A.back();
    for (int i = N - 2; i >= 0; i--) {
        ans += (sum * A[i]) % MOD;
        ans %= MOD;
        sum += A[i];
        sum %= MOD;
    }
    cout << ans << endl;
    return 0;
} // End of Code
