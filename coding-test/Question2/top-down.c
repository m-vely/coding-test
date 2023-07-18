#include <stdio.h>

#define MAX_N 1000000
int memo[MAX_N];

int fibonacciTopDown(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = fibonacciTopDown(n - 3) + fibonacciTopDown(n - 2);

    return memo[n];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Initialize the memoization table
    int i;
    for (i = 0; i < MAX_N; i++) {
        memo[i] = -1;
    }

    int result = fibonacciTopDown(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}


/* This approach is called the Top- Down Dynamic Programming Approach and it uses the concept of Memoization.

Advantages:

Dynamic Programming: Memoization helps avoid redundant calculations and improves efficiency by storing and reusing the previously computed values.
Better performance: With memoization, the time complexity reduces significantly compared to the recursive approach.

Disadvantages:

Limited by memory: The size of the memoization table limits the maximum value of n that can be computed.
Additional memory usage: The memoization table requires extra memory space to store the computed values.

**/

