#include <stdio.h>
#include <math.h>

int main() {
    int intA;
    // Input an integer from the user
    scanf("%d", &intA);

    // Calculate the cube of the input number
    double dbAncer = pow(intA, 3);
    int intAncer = (int)dbAncer;
    printf("%d\n", intAncer);
    
    return 0; // End of Code
