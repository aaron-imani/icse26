#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max = 0, cur = 0;

void solve(){
    int a = ni();
    int b = ni();

    cout << max(0, a-2*b) << endl;
}

int ni(){
    int a;
    cin >> a;
    return a;
}

int main() 
{ 
    solve();
    return 0;
}

// End of Code
