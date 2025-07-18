#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 100

int read_int() {
    int num;
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Error reading integer\n");
        exit(EXIT_FAILURE);
    }
    return num;
}

char* read_string() {
    char *str = (char *)malloc(MAX_LINE * sizeof(char));
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    if (fgets(str, MAX_LINE, stdin) == NULL) {
        fprintf(stderr, "Error reading string\n");
        free(str);
        exit(EXIT_FAILURE);
    }
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';
    return str;
}

int main() {
    int n = read_int();
    int m = read_int();

    int *penal = (int *)calloc(n + 1, sizeof(int));
    if (penal == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    bool *solved = (bool *)calloc(n + 1, sizeof(bool));
    if (solved == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(penal);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < m; i++) {
        int num = read_int();
        char *str = read_string();
        if (str[0] == 'A') {
            solved[num] = true;
        } else {
            if (!solved[num]) {
                penal[num]++;
            }
        }
        free(str); // Free the allocated string memory
    }

    int correct_ans = 0;
    int num_penal = 0;
    for (int i = 1; i <= n; i++) {
        if (solved[i]) {
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
