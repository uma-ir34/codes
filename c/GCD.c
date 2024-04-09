#include <stdio.h>

// Function to find GCD using consecutive integer checking method
int findGCD(int a, int b, int *opcount) {
    int gcd = 1;

    for (int i = 1; i <= a && i <= b; ++i) {
        (*opcount)++;  // Increment the operation count for each iteration
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

int main() {
    int num1, num2;
    int opcount = 0;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = findGCD(num1, num2, &opcount);

    printf("GCD: %d\n", result);
    printf("Number of operations (opcount): %d\n", opcount);

    return 0;
}
