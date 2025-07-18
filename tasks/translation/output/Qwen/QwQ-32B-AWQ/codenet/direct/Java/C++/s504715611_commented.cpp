#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cctype>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

struct UnionFind {
    vector<int> Parent;
    UnionFind(int n) : Parent(n, -1) {}
    int root(int A) {
        return Parent[A] < 0 ? A : (Parent[A] = root(Parent[A]));
    }
    int size(int A) { return -Parent[root(A)]; }
    bool connect(int A, int B) {
        int rootA = root(A), rootB = root(B);
        if (rootA == rootB) return false;
        if (size(rootA) < size(rootB)) swap(rootA, rootB);
        Parent[rootA] += Parent[rootB];
        Parent[rootB] = rootA;
        return true;
    }
};

class FastScanner {
private:
    static const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    int ptr = 0, buflen = 0;
    bool hasNextByte() {
        if (ptr < buflen) return true;
        ptr = 0;
        buflen = read();
        return buflen > 0;
    }
    int read() { return ::read(STDIN_FILENO, buffer, BUFFER_SIZE); }
    bool isPrintable(int c) { return 33 <= c && c <= 126; }
public:
    bool hasNext() {
        while (hasNextByte()) {
            int current = static_cast<int>(buffer[ptr]);
            if (isPrintable(current)) break;
            ptr++;
        }
        return hasNextByte();
    }
    string next() {
        if (!hasNext()) throw runtime_error("No more input");
        string result;
        int b = buffer[ptr++];
        while (isPrintable(b)) {
            result += static_cast<char>(b);
            if (!hasNextByte()) break;
            b = buffer[ptr++];
        }
        return result;
    }
    int nextInt() {
        if (!hasNext()) throw runtime_error("No input");
        int n = 0, minus = false;
        int b = readByte();
        if (b == '-') { minus = true; b = readByte(); }
        if (b < '0' || '9' < b) throw runtime_error("Invalid number format");
        while (true) {
            if (b >= '0' && b <= '9') n = n*1.0*10 + (b-'0');
            else if (b == -1 || !isPrintable(b)) return minus ? -n : n;
            else throw runtime_error("Invalid number format");
            b = readByte();
        }
    }
    int readByte() { return hasNextByte() ? buffer[ptr++] : -1; }
};

const long long mod = 1000000007;
const double eps = 1.0e-14;
const int big = INT_MAX;
const double PI = 3.14159265358979323846262338327950288;

int lower_bound(const int a[], int n, int key) {
    int l=0, r=n;
    while(r-l>1) {
        int m=(l+r)/2;
        if(a[m]<key) l=m; else r=m;
    }
    return l;
}

int upper_bound(const int a[], int n, int key) {
    int l=0, r=n;
    while(r-l>1) {
        int m=(l+r)/2;
        if(a[m]<=key) l=m; else r=m;
    }
    return l;
}

bool isPrime(long long n) {
    if(n ==2)return true;
    if(n<2 || n%2==0)return false;
    long long d=sqrt(n);
    for(long long i=3; i<=d; i+=2)
        if(n%i==0)return false;
    return true;
}

int upper_division(int a,int b) {
    return a%b==0 ? a/b : a/b+1;
}

long long modlcm(long long a,long long b) {
    return a*b*modint(gcd(a,b), mod);
}

long long gcd(long long a,long long b) {
    return b>0 ? gcd(b, a%b) :a;
}

long long modint(long long a,long long m) {
    long long b=m, u=1, v=0;
    while(b!=0) {
        long long t=a/b;
        a -= t*b;
        swap(a,b);
        u -= t*v;
        swap(u,v);
    }
    u %= m;
    if(u <0) u +=m;
    return u;
}

long long modpow(long long x,long long n,long long mo) {
    long long sum=1;
    while(n>0) {
        if(n&1) sum = sum *x % mo;
        x =x*x % mo;
        n >>=1;
    }
    return sum;
}

int main() {
    FastScanner scan;
    string s = scan.next();
    cout << (s.length() >=6 && s[2]==s[3] && s[4]==s[5] ? "Yes" : "No") << endl;
    return 0;
} // End of Code
