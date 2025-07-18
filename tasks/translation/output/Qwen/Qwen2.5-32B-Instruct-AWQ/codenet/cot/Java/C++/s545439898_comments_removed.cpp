#include <iostream>
using namespace std;

int main() {
    int count;
    cin >> count;
    int* givingNumbers = new int[count];

    for(int i = 0; i < count; i++) {
        cin >> givingNumbers[i];
    }

    for(int i = count - 1; 0 <= i; i--) {
        cout << givingNumbers[i];
        if(i > 0) {
            cout << " ";
        }
    }

    cout << endl;
    delete[] givingNumbers;
    // End of Code
