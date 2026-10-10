#include <stdio.h>

int main(void) {
    char operator;
    double num1, num2, result;

    printf("Enter first number: ");
    if (scanf("%lf", &num1) != 1) {
        fprintf(stderr, "Error: Please enter a valid number.\n");
        return 1;
    }

    printf("Enter an operator (+, -, *, /): ");
    if (scanf(" %c", &operator) != 1) {
        fprintf(stderr, "Error: Please enter a valid operator.\n");
        return 1;
    }

    printf("Enter second number: ");
    if (scanf("%lf", &num2) != 1) {
        fprintf(stderr, "Error: Please enter a valid number.\n");
        return 1;
    }

    switch (operator) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 == 0.0) {
                fprintf(stderr, "Error: Division by zero is not allowed.\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            fprintf(stderr, "Error: Invalid operator. Use +, -, *, or /.\n");
            return 1;
    }

    printf("%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
    return 0;
}
