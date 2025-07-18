#include <stdio.h>
#include <string.h>

int N;
int K;
long Q;
int A;
int B;
long C;
double min = 9999999;
long ans = 0;

int main() {
    int N;
    char s[1000];
    int flag = 0;
    int ans = 0;
    int hen = 0;
    int sha = 0;
    int dot = 0;
    int temp = 0;
    int first = 1;

    scanf("%d", &N);
    getchar();
    fgets(s, sizeof(s), stdin);

    for (int i = 0; i < N; i++) {
        if (s[i] == '#') {
            first = 0;
            if (sha <= dot) {
                ans += sha;
                sha = 0;
                dot = 0;
                first = 1;
            } else {
                // temp += dot;
            }
            sha++;
        } else {
            dot++;
        }
    }

    if (sha <= dot) {
        ans += sha;
        dot = 0;
    } else {
        // temp += dot;
    }

    printf("%d\n", ans + dot); // End of Code
}
