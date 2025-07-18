#include <iostream>
#include <vector>
#include <string>

class MyInput {
private:
    std::istream& in;

public:
    MyInput(std::istream& is) : in(is) {}

    int nextInt() {
        int value;
        in >> value;
        return value;
    }
};

class Solver {
public:
    void solve(int testNumber, MyInput& in, std::ostream& out) {
        int K = in.nextInt();
        int S = in.nextInt();
        int ans = 0;

        for (int x = 0; x <= K; x++) {
            for (int y = 0; y <= K; y++) {
                int z = S - x - y;
                if (z >= 0 && z <= K) {
                    ans++;
                }
            }
        }

        out << ans << std::endl;
    }
};

int main() {
    MyInput in(std::cin);
    std::ostream& out = std::cout;
    Solver solver;
    solver.solve(1, in, out);
    return 0;
}
// End of Code
