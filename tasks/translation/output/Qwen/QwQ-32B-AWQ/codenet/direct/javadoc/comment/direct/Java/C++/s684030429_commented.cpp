#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Main {
public:
    Main() {}
    void solve();
    static int ni();
    static long long nl();
    static float nf();
    static double nd();
    static string ns();
    static void ia(int a[]);
    static void la(long a[]);
    static void fa(float a[]);
    static void da(double a[]);
    static void sa(string a[], bool empty);
    static void ida(int a[][], int n, int m);
    static void lda(long a[][], int n, int m);
    static void dda(double a[][], int n, int m);
    static int stoi(string s);
    static double stod(string s);
    static long lmin(long a[]);
    static int imin(int a[]);
    static long lmax(long a[]);
    static int imax(int a[]);
    static bool ibs(int a[], int toFind);
    static bool lbs(long a[], long toFind);
    static int stb(string s);
};

void Main::solve() {
    int a = ni();
    int b = ni();
    cout << std::max(0, a - 2 * b) << endl;
}

int Main::ni() {
    int a;
    cin >> a;
    return a;
}

long long Main::nl() {
    long long a;
    cin >> a;
    return a;
}

float Main::nf() {
    float a;
    cin >> a;
    return a;
}

double Main::nd() {
    double a;
    cin >> a;
    return a;
}

string Main::ns() {
    string s;
    getline(cin, s);
    return s;
}

void Main::ia(int a[]) {
    for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
        a[i] = ni();
    }
}

void Main::la(long a[]) {
    for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
        a[i] = nl();
    }
}

void Main::fa(float a[]) {
    for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
        a[i] = nf();
    }
}

void Main::da(double a[]) {
    for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
        a[i] = nd();
    }
}

void Main::sa(string a[], bool empty) {
    if (empty) {
        for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
            a[i] = "";
        }
    } else {
        for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
            a[i] = ns();
        }
    }
}

void Main::ida(int a[][], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = ni();
        }
    }
}

int Main::stoi(string s) {
    return std::stoi(s);
}

double Main::stod(string s) {
    return std::stod(s);
}

long Main::lmin(long a[]) {
    long min = LLONG_MAX;
    for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
        if (min > a[i]) min = a[i];
    }
    return min;
}

int Main::imin(int a[]) {
    int min = INT_MAX;
    for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
        if (min > a[i]) min = a[i];
    }
    return min;
}

long Main::lmax(long a[]) {
    long max = LLONG_MIN;
    for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
        if (max < a[i]) max = a[i];
    }
    return max;
}

int Main::imax(int a[]) {
    int max = INT_MIN;
    for (int i = 0; i < (sizeof(a)/sizeof(a[0])); i++) {
        if (max < a[i]) max = a[i];
    }
    return max;
}

bool Main::ibs(int a[], int toFind) {
    sort(a, a + (sizeof(a)/sizeof(a[0])));
    int min = 0;
    int max = (sizeof(a)/sizeof(a[0])) -1;
    bool found = false;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) found = true;
        else if (toFind > a[mid]) min = mid +1;
        else max = mid -1;
    }
    return found;
}

bool Main::lbs(long a[], long toFind) {
    sort(a, a + (sizeof(a)/sizeof(a[0])));
    int min =0;
    int max = (sizeof(a)/sizeof(a[0]))-1;
    bool found = false;
    while (min <= max && !found) {
        int mid = min + (max - min)/2;
        if (a[mid] == toFind) found = true;
        else if (toFind > a[mid]) min = mid +1;
        else max = mid -1;
    }
    return found;
}

int Main::stb(string s) {
    int sum =0;
    int k=0;
    for (int i = s.length()-1; i >=0; i--) {
        sum += std::stoi(s.substr(i,1)) * pow(2, k++);
    }
    return sum;
}

int main() {
    Main().solve();
    return 0;
}

// End of Code
