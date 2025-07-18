#include <stdio.h>
#include <math.h>

int main() {
    int intA;
    // Input reading
    scanf("%d", &intA);

    // Calculation
    double dbAncer = pow(intA, 3);
    int intAncer = (int)dbAncer;

    // Output
    printf("%d\n", intAncer);
    // End of Code
}
