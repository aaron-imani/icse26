#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> queue;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        queue.push(num);
    }
    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += queue.top();
        queue.pop();
    }
    cout << (queue.top() < sum ? "Yes" : "No") << endl;
    return 0;
}
// End of Code
