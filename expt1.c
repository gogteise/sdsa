// 1. Write a C program to merge contents of two files containing USNs of students in a
// sorted order into the third file such that the third file contains Unique USNs.
// Program should also display common USNs in both the files.

// readme: (create 2 file in folder f1.txt and f2.txt enter values)

// program:


#include <stdio.h>
int main() {
    FILE *f1 = fopen("f1.txt", "r");
    FILE *f2 = fopen("f2.txt", "r");
    FILE *f3 = fopen("f3.txt", "w");
    int a, b;

    if (!f1 || !f2 || !f3)
        return printf("Error\n"), 1;

    int s1 = fscanf(f1, "%d", &a);
    int s2 = fscanf(f2, "%d", &b);
    printf("Common USNs: ");

    while (s1 == 1 && s2 == 1) {
        if (a < b) {
            fprintf(f3, "%d\n", a);
            s1 = fscanf(f1, "%d", &a);
        } else if (b < a) {
            fprintf(f3, "%d\n", b);
            s2 = fscanf(f2, "%d", &b);
        } else {
            fprintf(f3, "%d\n", a);
            printf("%d ", a);
            s1 = fscanf(f1, "%d", &a);
            s2 = fscanf(f2, "%d", &b);
        }
    }
    while (s1 == 1) { fprintf(f3, "%d\n", a);
    s1 = fscanf(f1, "%d", &a); }
    while (s2 == 1) { fprintf(f3, "%d\n", b);
    s2 = fscanf(f2, "%d", &b); }
    printf("\nmerged both file as f3.txt\n ");

    fclose(f1); fclose(f2); fclose(f3);
    return 0;
}
