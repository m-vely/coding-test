#include <stdio.h>

int fibonacciBottomUp(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

	int i;
    for (i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int result = fibonacciBottomUp(n);
    printf("F(%d) = %d\n", n, result);

    return 0;
}


/* This is the Bottom-Up approach which makes use of the concept of Tabulation.

Advantages:

Dynamic Programming: The bottom-up approach avoids recursive function calls, making it more efficient.
Optimal space usage: The tabulation method only requires an array of size n+1 to store the computed values.

Disadvantages:

Array size estimation: The size of the array (dp) needs to be estimated based on the maximum expected value of n.

**/


