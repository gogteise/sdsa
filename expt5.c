//5. Consider a super market scenario where sales manager wants to search for the customer details
//using a customer-id.Customer information like (custid, custname, & custphno) are stored in a structure,
//and custid will be used as hash key.Develop and execute a program in C using suitable data structures
//to implement the following operations:
//a. Insertion of a new data entry.
//b. Search for customer information using custid
//c. Display the records. (Demonstrate collision and its handling using linear probing method).

//PROGRAM:

#include <stdio.h>
#include <stdlib.h>

#define S 5
struct Cust {
    int id; char name[20];
    long ph;
    int used; } h[S];

void insert() {
    struct Cust c;
    printf("Enter customer ID, Name, PhoneNo: ");
    scanf("%d %s %ld", &c.id, c.name, &c.ph);
    int pos = c.id % S;
    for (int i = 0; i < S; i++) {
        int idx = (pos + i) % S;
        if (!h[idx].used) {
            h[idx] = c; h[idx].used = 1;
            return;
        }
    }
    printf("Full\n");
}

void search() {
    int key;
    printf("Enter ID to search: ");
    scanf("%d", &key);
    int pos = key % S;
    for (int i = 0; i < S; i++) {
        int idx = (pos + i) % S;
        if (h[idx].used && h[idx].id == key) {
            printf("Found at %d\n", idx); return;
        }
    }
    printf("Not Found\n");
}

int main() {
    int ch;
    for(int i=0; i<S; i++) h[i].used = 0;
    while (1) {
        printf("\n1.Insert \n2.Search \n3.Display \n4.Exit \n(choose 1-4): ");
        scanf("%d", &ch);
        if (ch == 1) insert();
        else if (ch == 2) search();
        else if (ch == 3)
            for(int i=0; i<S; i++)
                if(h[i].used)
                    printf("[%d]: %d %s\n", i, h[i].id, h[i].name);
                else printf("[%d]: Empty\n", i);
        else exit(0);
    }
}


