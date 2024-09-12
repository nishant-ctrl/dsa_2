/*
Write a program to partition an array of integers into two subarrays by rearranging its elements in such
a way that the first subarray contains odd numbers and the second subarray contains even numbers,
without using a second array, and without changing the relative ordering among the odd numbers and
the relative ordering among the even numbers. Take the numbers of the array as input from the user,
rearrange the numbers of the array to partition it, and then display the modified array as the final output
of your program. For example, the array {17, 14, 15, 10, 25, 40, 56, 46, 98, 77} will be partitioned and
modified to {17, 15, 25, 77, 14, 10, 40, 56, 46, 98}.
*/
#include<stdio.h>
void print_list(int list[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        printf("%d " ,list[i]);
    }
}
void partition(int list[] , int n)
{
    int temp;
    int odd=0;
    for(int i=0 ; i<n ; i++)
    {
        if(list[i]%2!=0)
        {
            temp=list[i];
            for(int j=i ; j>odd ; j--)
            {
                list[j]=list[j-1];
            }
            list[odd]=temp;
            odd++;
        }
    }
}
int main()
{
    int list[100];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d" ,&size);
    for(int i=0 ; i<size ; i++)
    {
        printf("Enter element %d: " ,i+1);
        scanf("%d" ,&list[i]);
    }
    printf("Original List\n");
    print_list(list,size);
    partition(list,size);
    printf("\nModified List\n");
    print_list(list,size);
    return 0;
}