//6.Consider a warehouse where the items have to be arranged in an ascending order.
//Develop and execute a program in C using suitable data structures to implement
//warehouse such that items can be traced easily

//PROGRAM:

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node* add(struct node *h, int val) {
    struct node *n = malloc(sizeof(struct node)), *c = h, *p = NULL;
    n->data = val;
    while (c && val > c->data) {
        p = c;
        c = c->next;
    }
    n->next = c;
    if (p == NULL) return n;
    p->next = n;
    return h;
}
int main() {
    struct node *h = NULL, *t;
    int ch, val;
    while (1) {
        printf("\n1.Add 2.Display 3.Exit: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Value: "); scanf("%d", &val);
            h = add(h, val);
        } else if (ch == 2) {
            for (t = h; t; t = t->next) printf("%d ", t->data);
        } else exit(0);
    }
}
