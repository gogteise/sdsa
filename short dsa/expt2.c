// 2. Consider a calculator that needs to perform checking the correctness of parenthesized arithmetic expressions and convert the same to postfix expression for evaluation.
// Develop and execute a program in C using suitable data structures to perform the same and print both the expressions.
// The input expression consists of single character operands and the binary operators +(plus), (minus), (multiply) and/ (divide).

// input= (A+B)/(C-D) , A/B+C*D , (A+B)*C
// program:

#include <stdio.h>
#include <ctype.h>

int pr(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return -1;
}

int main() {
    char exp[30], stack[30], *e;
    int top = -1;

    printf("Enter infix: ");
    scanf("%s", exp);

    for (e = exp; *e; e++) {
        if (isalnum(*e))
            printf("%c", *e);
        else if (*e == '(')
            stack[++top] = *e;
        else if (*e == ')') {
            while (top != -1 && stack[top] != '(') printf("%c", stack[top--]);
            top--; // Pop '('
        } else {
            while (top != -1 && pr(stack[top]) >= pr(*e)) printf("%c", stack[top--]);
            stack[++top] = *e;
        }
    }
    while (top != -1) printf("%c", stack[top--]);
    return 0;
}
