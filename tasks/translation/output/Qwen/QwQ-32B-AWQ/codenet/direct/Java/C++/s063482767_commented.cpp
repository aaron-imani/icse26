#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        min_heap.push(num);
    }
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += min_heap.top();
        min_heap.pop();
    }
    cout << (min_heap.top() < sum ? "Yes" : "No") << endl;
    return 0;
} // End of Code
