#include <stdio.h>
void print_list(int list[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        printf("%d " ,list[i]);
    }
}
void add_to_sorted_list(int list[] , int key , int count)
{
    if(count==0)
    {
        list[0]=key;
    }
    int i=count;
    int j=i-1;
    if(count!=0)
    {   while(list[j]>key && j>=0)
        {
            list[j+1]=list[j];
            j--;
        }   
        list[j+1]=key;
    }
}
int main()
{
    int n , key;
    int list[100];
    printf("Enter no. of elements: ");
    scanf("%d" ,&n);
    for(int i=0 ; i<n ; i++)
    {
        printf("Enter element %d: " ,i+1);
        scanf("%d" ,&key);
        add_to_sorted_list(list , key , i);
    }
    printf("Sorted List\n");
    print_list(list,n);
    return 0;
}