#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Main {
public:
    static void main() {
        solve(cin, cout);
    }

    static void solve(istream &in, ostream &out) {
        int t = 1;
        while (t--) {
            long long n = nextLong(in);
            long long m = nextLong(in);
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

    static void swap(char *chrr, int i, int j) {
        char temp = chrr[i];
        chrr[i] = chrr[j];
        chrr[j] = temp;
    }

    static int num(int n) {
        int a = 0;
        while (n > 0) {
            a += (n & 1);
            n >>= 1;
        }
        return a;
    }

    struct Pair {
        int u, v, i, val;
        Pair(int a, int b, int i) : u(a), v(b), i(i) {}
    };

    static bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6)
            if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }

    static long long gcd(long long a, long long b) {
        if (b == 0) return a;
        return a > b ? gcd(b, a % b) : gcd(a, b % a);
    }

    static long long fast_pow(long long base, long long n, long long M) {
        if (n == 0) return 1;
        if (n == 1) return base;
        long long halfn = fast_pow(base, n / 2, M);
        if (n % 2 == 0)
            return (halfn * halfn) % M;
        else
            return (((halfn * halfn) % M) * base) % M;
    }

    static long long modInverse(long long n, long long M) {
        return fast_pow(n, M - 2, M);
    }

    static void feedArr(long long arr[], istream &in) {
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
            arr[i] = nextLong(in);
    }

    static void feedArr(double arr[], istream &in) {
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
            arr[i] = nextDouble(in);
    }

    static void feedArr(int arr[], istream &in) {
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
            arr[i] = nextInt(in);
    }

    static void feedArr(string arr[], istream &in) {
        for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
            arr[i] = next(in);
    }

    static string printArr(int arr[]) {
        stringstream sbr;
        for (int i : arr)
            sbr << i << " ";
        return sbr.str();
    }

    static string printArr(long long arr[]) {
        stringstream sbr;
        for (long long i : arr)
            sbr << i << " ";
        return sbr.str();
    }

    static string printArr(string arr[]) {
        stringstream sbr;
        for (string i : arr)
            sbr << i << " ";
        return sbr.str();
    }

    static string printArr(double arr[]) {
        stringstream sbr;
        for (double i : arr)
            sbr << i << " ";
        return sbr.str();
    }

    static string next(istream &in) {
        string token;
        while (in >> token) {
            return token;
        }
        return "";
    }

    static int nextInt(istream &in) {
        return stoi(next(in));
    }

    static long long nextLong(istream &in) {
        return stoll(next(in));
    }

    static double nextDouble(istream &in) {
        return stod(next(in));
    }
};

int main() {
    Main::main();
    return 0;
}
// End of Code
