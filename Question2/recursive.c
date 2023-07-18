#include <stdio.h>

int fibonacciRecursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return fibonacciRecursive(n - 3) + fibonacciRecursive(n - 2);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result = fibonacciRecursive(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}

/* This is the recursive approach. It is the simplest but suffers from redundancy and potential stack overflow. 

Advantages:

Simplicity: Recursive approach follows the mathematical definition closely.
Easy to understand the logic and formula implementation.

Disadvantages:

Inefficiency: Recursive calls can lead to redundant computations, resulting in a high time complexity.
Stack Overflow: For large values of n, the recursive approach may lead to a stack overflow error due to excessive function calls.
**/

