#include <stdio.h>

long long fibonacci_iterative(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        long long fib_prev = 0;
        long long fib_current = 1;
        long long fib_next;
        for (int i = 2; i <= n; i++) {
            fib_next = fib_prev + fib_current;
            fib_prev = fib_current;
            fib_current = fib_next;
        }
        return fib_current;
    }
}

long long fibonacci_recursive(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int main() {
    int n;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    printf("Fibonacci ke-%d (Iteratif): %lld\n", n, fibonacci_iterative(n)); 

    printf("Fibonacci ke-%d (Rekursif): %lld\n", n, fibonacci_recursive(n)); 

    return 0;
}
