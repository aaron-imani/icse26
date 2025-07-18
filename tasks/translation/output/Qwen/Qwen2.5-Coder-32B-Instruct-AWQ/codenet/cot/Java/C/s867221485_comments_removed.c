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
    scanf("%d", &N);
    getchar(); // consume newline character

    char s[1000]; // assuming a maximum length for the string
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0; // remove newline character from the string

    int flag = 0;
    int ans = 0;
    int hen = 0;
    int sha = 0;
    int dot = 0;
    int temp = 0;
    int first = 1;
    for (int i = 0; i < N; i++) {
        if(s[i] == '#'){
            first = 0;
            if(sha <= dot){
                ans += sha;
                sha = 0;
                dot = 0;
                first = 1;
            }
            sha++;
        } else {
            dot++;
        }
    }

    if(sha <= dot){
        ans += sha;
        dot = 0;
    }

    printf("%d\n", ans + dot);
    return 0;
}
// End of Code
