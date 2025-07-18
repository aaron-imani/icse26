#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

const int mod = 1e9 +7;

struct FastScanner {
    istream& in;
    string buffer;
    stringstream ss;
    vector<string> tokens;
    size_t ptr;
public:
    FastScanner(istream& _in) : in(_in), ptr(0) {}
    
    string next() {
        loadTokensIfEmpty();
        if (ptr >= tokens.size()) {
            loadNextLine();
            loadTokensIfEmpty();
        }
        return tokens[ptr++];
    }
    
    string nextLine() {
        loadNextLine();
        return buffer;
    }
    
    int nextInt() { return stoi(next()); }
    long long nextLong() { return stoll(next()); }
    double nextDouble() { return stod(next()); }
    
    vector<int> nextIntArray(int n) {
        vector<int> arr(n);
        for(int i=0; i<n; i++) arr[i] = nextInt();
        return arr;
    }
    
    vector<long long> nextLongArray(int n) {
        vector<long long> arr(n);
        for(int i=0; i<n; i++) arr[i] = nextLong();
        return arr;
    }
    
private:
    void loadNextLine() {
        if (!getline(in, buffer)) {
            throw runtime_error("Error reading line.");
        }
        ss.clear();
        ss.str(buffer);
        tokens.clear();
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
        ptr = 0;
    }
    
    void loadTokensIfEmpty() {
        if (tokens.empty()) {
            loadNextLine();
        }
    }
};

int rec(int v, int parent, vector<int>& dp, const vector<vector<int>>& to) {
    int res = 1;
    for(int next : to[v]) {
        if(next == parent) continue;
        res += rec(next, v, dp, to);
    }
    dp[v] = res;
    return res;
}

long long modpow(long long x, long long y) {
    long long res = 1;
    while(y > 0) {
        if(y % 2 == 1) res = res * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return res;
}

int main() {
    FastScanner fs(cin);
    int N = fs.nextInt();
    vector<vector<int>> to(N);
    vector<pair<int, int>> edges;
    for(int i=0; i<N-1; i++) {
        int A = fs.nextInt()-1, B = fs.nextInt()-1;
        to[A].push_back(B);
        to[B].push_back(A);
        edges.push_back({B, A});
    }
    vector<int> dp(N);
    rec(0, -1, dp, to);
    
    long long mulsum = 0;
    for(auto& e : edges) {
        int candidate1 = e.first;
        int candidate2 = e.second;
        int child;
        if(dp[candidate1] > dp[candidate2]) {
            child = candidate2;
        } else {
            child = candidate1;
        }
        long long a = dp[child];
        long long b = N - a;
        long long term = ( (modpow(2, a) -1) % mod ) * ( (modpow(2, b) -1) % mod ) % mod;
        mulsum = (mulsum + term) % mod;
    }
    
    long long cases = modpow(2, N);
    long long PN = (mulsum + (cases -1 + mod) % mod) % mod;
    long long BN = (N * modpow(2, N-1)) % mod;
    long long WN = (PN - BN + mod) % mod;
    long long ans = WN * modpow(cases, mod-2) % mod;
    
    cout << ans << endl;
    return 0;
}
// End of Code
