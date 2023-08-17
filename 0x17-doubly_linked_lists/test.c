#include <stdio.h>

int is_palindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return original == reversed;
}

int main() {
    int max_palindrome = 0;
    int num1, num2;

    for (num1 = 999; num1 >= 100; num1--) {
        for (num2 = num1; num2 >= 100; num2--) {
            int product = num1 * num2;
            if (is_palindrome(product) && product > max_palindrome) {
                max_palindrome = product;
            }
        }
    }

    FILE *file = fopen("102-result", "w");
    fprintf(file, "%d", max_palindrome);
    fclose(file);

    return 0;
}

