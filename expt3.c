//3. A calculator needs to evaluate a postfix expression.
//Develop and execute a program in C using a suitable data structure to evaluate a valid postfix expression.
//Assume the postfix expression is read as a single line consisting of non-negative single digit operands and binary arithmetic operators.
//The arithmetic operators are + (add), (subtract), (multiply) and / (divide).

//input: 53+82/* , 12+3*4- , 72-4*
// PROGRAM:

#include <stdio.h>
#include <ctype.h>
int main() {
    char exp[30];
    double stk[30], op1, op2;
    int t = -1;
    printf("Enter postfix: ");
    scanf("%s", exp);
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            stk[++t] = exp[i] - '0';
        } else {
            op2 = stk[t--];
            op1 = stk[t--];
            switch (exp[i]) {
                case '+': stk[++t] = op1 + op2; break;
                case '-': stk[++t] = op1 - op2; break;
                case '*': stk[++t] = op1 * op2; break;
                case '/': stk[++t] = op1 / op2; break;
            }
        }
    }
    printf("Result: %.2f\n", stk[t]);
    return 0;
}
