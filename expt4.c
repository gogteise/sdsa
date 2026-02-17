// 4. Write a C program to simulate working of a Messaging System in which a message is placed in a Queue by a Message Sender,
// a message is removed from the queue by a Message Receiver, which can also display the contents of the Queue.

// PROGRAM:

#include <stdio.h>
#include <stdlib.h>

int main() {
    int q[5], f = -1, r = -1, ch, x;

    while (1) {
        printf("\n1.insert(send) 2.Delete(Receive) 3.Display 4.Exit: ");
        if (scanf("%d", &ch) == EOF) break;

        switch (ch) {
            case 1:
                if (r == 4) printf("Full");
                else { if (f == -1) f = 0;
                printf("ID: ");
                scanf("%d", &q[++r]); }
                break;
            case 2:
                if (f == -1 || f > r)
                    printf("Empty");
                else { printf("Got: %d", q[f++]);
                if (f > r) f = r = -1; }
                break;
            case 3:
                if (f == -1 || f > r)
                    printf("Empty");
                else for (int i = f; i <= r; i++)
                printf("%d ", q[i]);
                break;
            case 4: exit(0);
        }
    }
    return 0;
}
