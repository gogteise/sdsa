//7. Consider a polynomial addition for two polynomials.
//Develop and execute a program in C using suitable data structures to implement the same

//PROGRAM:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node {
    int c, d;
    struct node *next;
};
struct node* create() {
    int i, n, c, d;
    struct node *head = malloc(sizeof(struct node)), *last;
    head->next = head;
    last = head;

    printf("No. of terms of polynomial: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        struct node *new = malloc(sizeof(struct node));
        printf("Coeff & Deg: ");
        scanf("%d%d", &new->c, &new->d);
        new->next = head;
        last->next = new;
        last = new;
    }
    return head;
}
int main() {
    struct node *h = create(), *t;
    int x, res = 0;
    printf("Enter x: ");
    scanf("%d", &x);
    for (t = h->next; t != h; t = t->next)
        res += t->c * pow(x, t->d);
    printf("the sum is: %d\n", res);
    return 0;
}
