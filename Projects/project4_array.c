//Standard input/output header.
//I'm adding a lot more comments than last time, to account for TA feedback. Trying to build good habits.
#include <stdio.h>
// Function prototype for the find_elements function which will use pointer arithmetic.
int find_elements(int *a, int n1, int *b, int n2, int *c) ;
/*
Main function which will call the find_elements function and print the results.
First declares the list length for both lists, prompts user for 4 inputs, array length, array elements for both arrays.
As specified in the instuctions, uses pointer arithmetic instead of subscripting to visit array elements.
*/
int main()
{
    int n1, n2;
/*
Asks user for length and elements of first array. Prints the text, scans the results. For the elements, uses a for loop to enter each integer into the array.
Does this for both the first and second arrays, with the same process.
As soon as I get both lengths, I find the length of array c, the combined array and call the function to determine array overlap.
*/
    printf("Enter length of the first array: ");
    scanf("%d", &n1);

    int a[n1];

    printf("Enter elements in the first array: ");
        for (int i=0; i<n1; i++)
        scanf("%d", &a[i]);

    printf("Enter length of the second array: ");
    scanf("%d", &n2);

    int b[n2];

//Now that I know the lengths of both i'm just going to add them for the length of array c, or the combined list of students. I need one more input though.
    int c[n1+n2];

    printf("Enter elements in the second array: ");
    for (int i=0; i<n2; i++)
        scanf("%d", &b[i]);

//I've gotten all the info I need. Beginning function call and output.
    int result = find_elements(a, n1, b, n2, c);
    printf("Output:");
        for (int i = 0; i < result; i++)
            printf(" %d", c[i]);

    printf("\n");
    return 0;
}

//Definition for find_elements function.
int find_elements(int *a, int n1, int *b, int n2, int *c)
{
    int *pa = a;
    int *pb = b;
    int *pc = c;
    int *temp;
    int count = 0;
    int found;
//Copy all of the elements of a into c.
    while (pa < a + n1) {
        *pc = *pa;
        pc++;
        pa++;
        count++;
    }
//Check the elements of b
    while (pb < b + n2) {
        found = 0;
        temp = c;
//Checks if already in c
        while (temp < c + count) {
            if (*temp == *pb) {
                found = 1;
                break;
            }
            temp++;
        }
//If not found, add to c
        if (!found) {
            *pc = *pb;
            pc++;
            count++;
        }
        pb++;
    }
    return count;
}
