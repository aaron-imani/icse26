#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Main {
private:
    istream& in;
    int max, cur;
public:
    Main(istream& is = cin) : in(is), max(0), cur(0) {}
    
    // Input methods
    int ni() { int a; in >> a; return a; }
    long long nl() { long long a; in >> a; return a; }
    float nf() { float a; in >> a; return a; }
    double nd() { double a; in >> a; return a; }
    string ns() { string s; getline(in, s); return s; }
    
    // Array input methods
    void ia(int a[], int n) { for(int i=0; i<n; i++) a[i] = ni(); }
    void la(long long a[], int n) { for(int i=0; i<n; i++) a[i] = nl(); }
    void fa(float a[], int n) { for(int i=0; i<n; i++) a[i] = nf(); }
    void da(double a[], int n) { for(int i=0; i<n; i++) a[i] = nd(); }
    void sa(string a[], bool empty, int n) {
        if(empty) {
            for(int i=0; i<n; i++) a[i] = "";
        } else {
            for(int i=0; i<n; i++) a[i] = ns();
        }
    }
    
    // Min/max functions
    int imin(int a[], int n) {
        int min = INT_MAX;
        for(int i=0; i<n; i++) {
            if(a[i] < min) min = a[i];
        }
        return min;
    }
    int imax(int a[], int n) {
        int max = INT_MIN;
        for(int i=0; i<n; i++) {
            if(a[i] > max) max = a[i];
        }
        return max;
    }
    long long lmin(long long a[], int n) {
        long long min = LLONG_MAX;
        for(int i=0; i<n; i++) {
            if(a[i] < min) min = a[i];
        }
        return min;
    }
    long long lmax(long long a[], int n) {
        long long max = LLONG_MIN;
        for(int i=0; i<n; i++) {
            if(a[i] > max) max = a[i];
        }
        return max;
    }
    
    // Binary search functions
    bool ibs(int a[], int n, int toFind) {
        sort(a, a+n);
        int left = 0, right = n-1;
        bool found = false;
        while(left <= right && !found) {
            int mid = left + (right - left)/2;
            if(a[mid] == toFind) found = true;
            else if(toFind > a[mid]) left = mid+1;
            else right = mid-1;
        }
        return found;
    }
    bool lbs(long long a[], int n, long long toFind) {
        sort(a, a+n);
        int left = 0, right = n-1;
        bool found = false;
        while(left <= right && !found) {
            int mid = left + (right - left)/2;
            if(a[mid] == toFind) found = true;
            else if(toFind > a[mid]) left = mid+1;
            else right = mid-1;
        }
        return found;
    }
    
    // String to binary
    int stb(const string& s) {
        int sum = 0, k = 0;
        for(int i = s.size()-1; i >=0; i--) {
            int digit = s[i] - '0';
            sum += digit * pow(2, k++);
        }
        return sum;
    }
    
    // Solve method
    void solve() {
        //        int n = ni();
        //        int m = ni();
        //        int s[] = new int[n];
        //        ia(s, n);
        //        int roads[n][n];
        //        for(int i =0; i<m; i++) {
        //            int p = ni();
        //            int q = ni();
        //            roads[p-1][q-1] = 1;
        //            roads[q-1][p-1] = 1;
        //        }
        //        for(int i=0; i<n; i++) {
        //            for(int j=0; j<n; j++) {
        //                cout << roads[i][j] << " ";
        //            }
        //            cout << endl;
        //        }
        //        int start = ni()-1;
        //        findRoads(roads[start], roads, start, s);
        //        cout << max << endl;
        
        int a = ni();
        int b = ni();
        cout << max(0, a - 2*b) << endl;
    }
};

int main() {
    Main m;
    m.solve();
    return 0;
}
// End of Code
