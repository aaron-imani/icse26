#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    int sum = 0;
    for(int i = 0; i < n - 1; i++) {
        sum += pq.top();
        pq.pop();
    }
    cout << (pq.top() < sum ? "Yes" : "No") << endl;
} // End of Code
