//9. Develop and execute a program in C using suitable data structures to create a binary tree for an expression.
//The tree traversals in some proper method should result in conversion of original expression into prefix, infix and postfix forms.
//Display the original expression along with the three different forms also.

//PROGRAM:

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int d;
    struct Node *l, *r;
};
struct Node* ins(struct Node* root, int d) {
    if (!root) {
        struct Node* n = malloc(sizeof(struct Node));
        n->d = d; n->l = n->r = NULL;
        return n;
    }
    if (d < root->d) root->l = ins(root->l, d);
    else if (d > root->d) root->r = ins(root->r, d);
    return root;
}
void trav(struct Node* n, int type) {
    if (!n) return;
    if (type == 0)
        printf("%d ", n->d);
    trav(n->l, type);
    if (type == 1)
    printf("%d ", n->d);
    trav(n->r, type);
    if (type == 2)
    printf("%d ", n->d);
}
int main() {
    struct Node* root = NULL;
    int a[] = {10, 20, 30, 40, 50, 60, 70}, i;
    for (i = 0; i < 7; i++) root = ins(root, a[i]);
    char *m[] = {"Preorder", "Inorder", "Postorder"};
    for (i = 0; i < 3; i++) {
        int order[] = {1, 0, 2};
        printf("%s traversal: ", i==0?"Inorder":i==1?"Preorder":"Postorder");
        trav(root, order[i]);
        printf("\n");
    }
    return 0;
}
