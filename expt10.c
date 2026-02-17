//10.Develop and execute a program in C using suitable data structures to perform
//Searching a data item in an ordered list of items in both directions and implement the following operations:
//1. Create a doubly linked list by adding each node at the start.
//2. Insert a new node at the end of the list.
//3. Display the content of a list.Consider an integer number as a data item

//PROGRAM:

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *L, *R;
} *head = NULL, *tail = NULL;
void add(int pos) {
    struct node *n = malloc(sizeof(struct node));
    printf("Enter data for node: ");
    scanf("%d", &n->data);
    n->L = n->R = NULL;

    if (!head) {
        head = tail = n;
    } else if (pos == 1) {
        n->R = head;
        head->L = n;
        head = n;
    } else { //
        tail->R = n;
        n->L = tail;
        tail = n;
    }
}
void display() {
    struct node *t = head;
    if (!t) printf("Empty");
    while (t) {
        printf("%d ", t->data);
        t = t->R;
    }
}
int main() {
    int ch;
    while (1) {
             printf("\n===Doubly linked list=== ");
        printf("\n1.Createlist \n2.Insertlist \n3.Display \n4.Exit ");
         printf("\nEnter your choice: ");
        scanf("%d", &ch);
        if (ch == 1 || ch == 2) add(ch);
        else if (ch == 3) display();
        else exit(0);
    }
    return 0;
}
