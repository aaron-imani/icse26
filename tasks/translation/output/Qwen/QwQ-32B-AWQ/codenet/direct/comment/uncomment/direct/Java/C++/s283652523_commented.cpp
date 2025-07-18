#include <iostream>
#include <vector>
using namespace std;

class FastScanner {
private:
    static const int BUFFER_SIZE = 1 << 20;
    char buffer[BUFFER_SIZE];
    size_t buf_pos = 0, buf_size = 0;
    FILE* input;
public:
    FastScanner(FILE* stream = stdin) : input(stream == stdin ? stdin : fopen("input.txt", "r")) {}
    ~FastScanner() {
        if (input != stdin) fclose(input);
    }
    int getChar() {
        if (buf_pos >= buf_size) {
            buf_size = fread(buffer, 1, BUFFER_SIZE, input);
            buf_pos = 0;
            if (buf_size == 0) return -1;
        }
        return buffer[buf_pos++];
    }
    int nextInt() {
        int c = getChar();
        while (c != -1 && (c < '0' || c > '9') && c != '-') c = getChar();
        if (c == -1) return -1;
        bool neg = (c == '-');
        int x = 0;
        if (neg) c = getChar();
        while (c >= '0' && c <= '9') {
            x = x * 10 + (c - '0');
            c = getChar();
        }
        return neg ? -x : x;
    }
    vector<int> nextIntArray(int n) {
        vector<int> res(n);
        for (int i = 0; i < n; ++i) res[i] = nextInt();
        return res;
    }
};

class Main {
private:
    FastScanner in;
    static const int MOD = 1e9 + 7;
public:
    void solve() {
        int N = in.nextInt();
        vector<int> A = in.nextIntArray(N);
        long long ans = 0, sum = A.back();
        for (int i = N - 2; i >= 0; --i) {
            ans += (sum * A[i]) % MOD;
            ans %= MOD;
            sum += A[i];
            sum %= MOD;
        }
        cout << ans << endl;
    }
    void m() {
        in = FastScanner(stdin);
        solve();
    }
};

int main() {
    Main().m();
    return 0;
}
// End of Code
