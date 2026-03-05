//Standard input/output header file.
#include <stdio.h>
//Required function
void compute(int *a1, int n1, int *a2, int n2);

//Main function.
int main()
{
    int n1;
    printf("Enter the length of the array: ");
    scanf("%d",&n1);
//Declare the array lengths, compute the length of the output array which is always half of the input array plus 1. Integer division so even numbers don't kill the program.
    int a1[n1];
    int n2= (n1+1)/2;
    int a2[n2];

    printf("Enter the elements of the array: ");
    for (int i=0;i < n1;i++)
    {
        scanf("%d", &a1[i]);
    }
    compute(a1, n1, a2, n2);
//Output, prints number with a space before them, output with no space after. Newline after the output.
    printf("Output:");

    for (int i = 0; i < n2; i++)
    {
        printf(" %d", a2[i]);
    }

    printf("\n");

    return 0;
}

//Compute function definition. Left and right refer to the firstmost and lastmost value respectively.
void compute(int *a1, int n1, int *a2, int n2)
{
    int *left = a1;
    int *right = a1 + n1 - 1;
    int *out = a2;

    while (left < right)
    {
        *out = *left + *right;
        left++;
        right--;
        out++;
    }
//Checks if the number is the middle one. If so, that number goes to the final value in the array.
    if (left == right)
    {
        *out = *left;
    }
}
