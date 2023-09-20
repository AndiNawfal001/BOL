#include <stdio.h>

// Function to swap two integers using pass-by-value
void valueSwap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to swap two integers using pass-by-reference
void referenceSwap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 55;
    int num2 = 77;

    // Pass by Value
    printf("\033[0;32mPass-by-Value:\033[0m\n");
    printf("Before swap: \n firstNum=%d secondNum=%d\n", num1, num2);
    valueSwap(num1, num2);
    printf("After swapping: \n firstNum=%d secondNum=%d\n\n", num1, num2);

    // Pass by Reference
    printf("\033[0;32mPass-by-Reference:\033[0m\n");
    printf("Before swap: \n firstNum=%d secondNum=%d\n", num1, num2);
    referenceSwap(&num1, &num2);
    printf("After swapping: \n firstNum=%d secondNum=%d\n", num1, num2);

    return 0;
}
