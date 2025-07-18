#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int num = scanf("%d", &num); // Wait, no! Wait, here's a mistake. Wait, in the code I wrote earlier, the first input is read as:

Wait a second, in my previous outline, I had:

int num;
scanf("%d", &num);

But in the code above, I wrote:

Wait, looking at the code I wrote:

The first part after reading N is:

int num;
scanf("%d", &num);

But in the code I just wrote, I have:

Wait in my code above, the first part after reading N is:

int num = scanf("%d", &num); 

Wait no, that's a mistake. Wait no, in the code I wrote earlier, the code is:

Wait let me re-examine my code.

Wait in my initial code outline:

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int num;
    scanf("%d", &num);
    int max = num, min = num;
    // etc.

Ah, right. So in the code I wrote earlier, that's correct. But in the code I was just thinking of, I had a typo. So the correct code is as above.

Wait, the user's Java code does:

int N = sc.nextInt();
int max, min; max = min = sc.nextInt();

So in C, after reading N, read the first number, and set max and min to it.

So the code is correct as written.

So the correct C code is:

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int num;
    scanf("%d", &num);
    int max = num, min = num;
    for (int i = 1; i < N; i++) {
        int in;
        scanf("%d", &in);
        if (in > max) max = in;
        if (in < min) min = in;
    }
    printf("%d\n", max - min);
    return 0;
}

Yes, that's correct. So the final code is as above. I need to make sure that's exactly what I output.
