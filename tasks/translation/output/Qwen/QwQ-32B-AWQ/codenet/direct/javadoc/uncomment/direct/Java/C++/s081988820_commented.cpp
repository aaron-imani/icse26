#include <iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    int c[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }
    
    int min_dist[10];
    for (int i = 0; i < 10; i++) {
        min_dist[i] = c[i][1];
    }
    
    for (int tc = 0; tc < 10; tc++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (min_dist[i] > c[i][j] + min_dist[j]) {
                    min_dist[i] = c[i][j] + min_dist[j];
                }
            }
        }
    }
    
    int ans = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            int A;
            cin >> A;
            if (A >= 0) {
                ans += min_dist[A];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// End of Code
