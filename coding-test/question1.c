#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    enum TypeTag {
        ADD,
        MUL,
        SUB,
        FIBO
    } type;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(enum TypeTag type, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* makeFunc(enum TypeTag type) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int fibonacci(int n, int* dp) {
    if (dp[n] != -1) {
        return dp[n];
    }

    if (n == 0 || n == 1) {
        dp[n] = n;
        return n;
    }

    int result = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    dp[n] = result;
    return result;
}

void calc(Node* node) {
    switch (node->type) {
        case ADD:
            printf("add : %d\n", node->value);
            break;
        case MUL:
            printf("mul : %d\n", node->value);
            break;
        case SUB:
            printf("sub : %d\n", node->value);
            break;
        case FIBO:
            printf("fibo : %d\n", node->value);
            break;
        default:
            printf("Invalid node type\n");
            break;
    }
}

int main() {
    Node* add = makeNode(ADD, 16);
    Node* mul = makeNode(MUL, 20);
    Node* sub = makeNode(SUB, -4);
    Node* fibo = makeNode(FIBO, 3);

    int n = fibo->value;
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    int i;
    for (i = 0; i <= n; i++) {
        dp[i] = -1;
    }

    int fiboValue = fibonacci(n, dp);
    fibo->value = fiboValue;

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    free(add);
    free(mul);
    free(sub);
    free(fibo);
    free(dp);

    return 0;
}

