#include<stdio.h>
void Insert(int list[] , int x , int p , int *k)
{
    if(p<1 || p>*k+2)
    {
        printf("Invalid position,\n");
        return;
    }
    for(int i=(*k) ; i>=0 ; i--)
    {
        if(i==p-1)
        {
            list[i]=x;
            (*k)++;
            break;
        }
        list[i]=list[i-1];
    }
}
int Delete(int list[] , int p , int *k)
{
    // if(p<1 || p>*k)
    // {
    //     printf("Invalid position,\n");
    //     return;
    // }
    int temp;
    for(int i=0 ; i<*k ; i++)
    {
        if(i==p-1)
        {
            temp=list[i];
            for(int j=i ; j<*k-1 ; j++)
            {
                list[j]=list[j+1];
            }
            (*k)--;
            return temp;
        }
    }
}
void Empty(int list[] , int *k)
{
    *k=0;
    printf("List is emptied successfully.");
}
void Display(int list[] , int k)
{
    if(k==0)
    {
        printf("List is Empty.\n");
    }
    for(int i=0 ; i<k ; i++)
    {
        printf("%d " ,list[i]);
    }
}
int main()
{
    int list[100] , k;
    printf("Enter the size of the array: ");
    scanf("%d" ,&k);
    for(int i=0 ; i<k ; i++)
    {
        printf("Enter %d element: " ,i+1);
        scanf("%d" ,&list[i]);
    }
    int choice , element , position;
    int temp;
    while(1)
    {
        printf("\n\tMENU\t\n");
        printf("1.Insert\n2.Delete\n3.Empty\n4.Display\n5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d" ,&choice);
        switch(choice)
        {
            case 1: printf("Enter element to insert: ");
                    scanf("%d" ,&element);
                    printf("Enter position: ");
                    scanf("%d" ,&position);
                    Insert(list,element,position,&k);
                    break;
            case 2: printf("Enter position of element to delete: ");
                    scanf("%d" ,&position);
                    temp=Delete(list,position,&k);
                    printf("Deleted item : %d" ,temp);
                    break;
            case 3: Empty(list,&k);
                    break;
            case 4: Display(list,k);
                    break;
            case 5: printf("Exiting Program.");
                    return 0;        
            default:printf("Invalid Choice");
                    break;
        }
    }
}