#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int ans = 100;
std::vector<std::pair<int, int>> balls;
int N;
std::vector<bool> taken;

int min(int a, int b) { return std::min(a, b); }
int max(int a, int b) { return std::max(a, b); }
long abs(long x) { return std::abs(x); }
long ceil(long num, long den) { return (num % den != 0) ? (num / den + 1) : (num / den); }
long GCD(long a, long b) {
    if (a == 0 || b == 0) return std::max(a, b);
    return GCD(std::min(a, b), std::max(a, b) % std::min(a, b));
}
long FastExp(long base, long exp, long mod) {
    long ans = 1;
    while (exp > 0) {
        if (exp % 2 == 1) ans = (ans * base) % mod;
        exp /= 2;
        base = (base * base) % mod;
    }
    return ans;
}
long ModInv(long num, long mod) { return FastExp(num, mod - 2, mod); }
int pop(long x) {
    int cnt = 0;
    while (x > 0) {
        if (x % 2 == 1) cnt++;
        x /= 2;
    }
    return cnt;
}

void solve() {
    for (int add = 1; add < N; add++) {
        taken = std::vector<bool>(N, false);
        int p = balls[add].first - balls[0].first;
        int q = balls[add].second - balls[0].second;

        ans = min(ans, check(p, q));
    }
}

int check(int p, int q) {
    int ret = 0;
    while (true) {
        bool added = false;
        int start = 0;
        int x = -1;
        int y = -1;

        for (int i = 0; i < N; i++) {
            if (!taken[i]) {
                added = true;
                ret++;
                start = i;
                taken[i] = true;
                x = balls[i].first + p;
                y = balls[i].second + q;
                break;
            }
        }
        if (!added) break;
        for (int i = start + 1; i < N; i++) {
            if (balls[i].first == x && balls[i].second == y) {
                taken[i] = true;
                x += p;
                y += q;
            }
        }
    }
    return ret;
}

int main() {
    std::cin >> N;
    ans = N;
    balls.resize(N);
    for (int i = 0; i < N; i++) {
        std::cin >> balls[i].first >> balls[i].second;
    }
    std::sort(balls.begin(), balls.end());
    solve();
    for (int i = 0; i < N; i++) {
        std::swap(balls[i].first, balls[i].second);
    }
    std::sort(balls.begin(), balls.end());
    solve();
    std::cout << ans << std::endl;
    return 0;
}
// End of Code
