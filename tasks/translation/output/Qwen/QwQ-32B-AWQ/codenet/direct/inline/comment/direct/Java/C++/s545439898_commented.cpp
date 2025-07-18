#include <iostream>
#include <vector>
using namespace std;

int main() {
    int count;
    cin >> count;
    vector<int> givingNumbers(count);
    for(int i = 0; i < count; i++) {
        cin >> givingNumbers[i];
    }
    for(int i = count -1; i >= 0; i--) {
        cout << givingNumbers[i];
        if(i > 0) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
// End of Code
