#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

char* readLine() {
    char* line = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(line, MAX_LINE_LENGTH, stdin);
    return line;
}

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

char* next() {
    char* token = (char*)malloc(MAX_LINE_LENGTH * sizeof(char));
    scanf("%s", token);
    return token;
}

int main() {
    int n = nextInt();
    int m = nextInt();

    int* penal = (int*)malloc((n + 1) * sizeof(int));
    int* solved = (int*)malloc((n + 1) * sizeof(int));
    memset(solved, 0, (n + 1) * sizeof(int));

    for (int i = 0; i < m; i++) {
        int num = nextInt();
        char* str = next();
        if (str[0] == 'A') {
            solved[num] = 1;
        } else {
            if (solved[num] == 0) {
                penal[num]++;
            }
        }
        free(str);
    }

    int correct_ans = 0;
    int num_penal = 0;
    for (int i = 1; i <= n; i++) {
        if (solved[i] == 1) {
            correct_ans++;
            num_penal += penal[i];
        }
    }

    printf("%d %d\n", correct_ans, num_penal);

    free(penal);
    free(solved);
    return 0;
}
// End of Code
