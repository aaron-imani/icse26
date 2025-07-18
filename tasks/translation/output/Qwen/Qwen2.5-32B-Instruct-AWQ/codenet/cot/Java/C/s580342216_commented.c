#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    FILE *input;
} Solution;

Solution *new_solution() {
    Solution *solution = (Solution *)malloc(sizeof(Solution));
    solution->input = stdin;
    return solution;
}

void run_case(Solution *solution) {
    char line[100];
    fgets(line, sizeof(line), solution->input);
    int N = atoi(strtok(line, " "));
    int K = atoi(strtok(NULL, " "));

    int len = 0;
    while (N > 0) {
        N /= K;
        len++;
    }

    printf("%d\n", len);
}

int main() {
    Solution *solution = new_solution();
    while (!feof(solution->input)) {
        run_case(solution);
    }
    free(solution);
    return 0;
}

// End of Code
