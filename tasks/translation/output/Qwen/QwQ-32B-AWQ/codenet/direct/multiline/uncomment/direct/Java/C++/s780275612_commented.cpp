#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int intA;
    cin >> intA;
    double dbAncer = pow(intA, 3);
    int intAncer = static_cast<int>(dbAncer);
    cout << intAncer << endl;
    return 0;
}
// End of Code
