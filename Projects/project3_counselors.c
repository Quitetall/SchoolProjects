/*
 * Name: brian lam
 * Program: project3_counselors.c
 * Purpose: Find the counselor number that has not been assigned.
 */

#include <stdio.h>

/*
 * searches the array counselors and returns the counselor that hasn't been assigned.
 * n is the total number of counselors.
 */
int search(int counselors[], int n) {
    int totalSum = n * (n + 1) / 2;
    int assignedSum = 0;

    for (int i = 0; i < n - 1; i++) {
        assignedSum += counselors[i];
    }

    return totalSum - assignedSum;
}

int main(void) {
    int n;

    printf("Enter number of counselors: ");
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    if (n <= 1) {
        printf("Counselor has not been assigned: %d\n", 1);
        return 0;
    }

    int counselors[n - 1];

    printf("Enter counselors assigned: ");
    for (int i = 0; i < n - 1; i++) {
        if (scanf("%d", &counselors[i]) != 1) {
            return 0;
        }
    }

    int missing = search(counselors, n);

    printf("Counselor has not been assigned: %d\n", missing);

    return 0;
}
