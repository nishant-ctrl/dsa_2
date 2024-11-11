#include<stdio.h>
void Display(int q[] , int k)
{
    if(k==0)
    {
        printf("Queue is Empty.\n");
    }
    for(int i=0 ; i<k ; i++)
    {
        printf(" %d" , q[i]);
    }
}
int IsEmpty(int q[] , int k)
{
    if(k==0)
    {
        return  1;
    }
    else
    {
        return 0;
    }
}
int IsFull(int q[] , int k , int max)
{
    if(k==max)
    {
        return  1;
    }
    else
    {
        return 0;
    }
}
void addAtRear(int q[] , int x , int *k , int max)
{
    if(IsFull(q, *k , max)==1)
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        q[*k]=x;
        (*k)++;
    }
}
void addAtFront(int q[] , int x , int *k , int max)
{
    if(IsFull(q, *k , max)==1)
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        for(int i=*k ; i>0 ; i--)
        {
            q[i]=q[i-1];
        }
        q[0]=x;
        (*k)++;
    }
}
void deleteFromFront(int q[] , int *k)
{
    if(IsEmpty(q , *k)==1)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        for(int i=0 ; i<(*k-1) ; i++)
        {
            q[i]=q[i+1];
        }
        (*k)--;
    }
}
void deleteFromRear(int q[] , int *k)
{
    if(IsEmpty(q , *k)==1)
    {
        printf("Queue Underflow.\n");
    }
    else
    {
        (*k)--;
    }
}
int main()
{
    int q[100];
    int max,k;
    printf("Enter the maximum size of the queue: ");
    scanf("%d" ,&max);
    start:
    printf("How many elements you want to enter initially: ");
    scanf("%d" ,&k);
    if(k>max)
    {
        printf("Invalid  input\n");
        goto start;
    }
    for(int i=0;i<k;i++)
    {
        printf("Enter element %d : " ,i+1);
        scanf("%d" ,&q[i]);
    }
    int choice;
    int x;
    while(1)
    {
        printf("\n--MENU--\n");
        printf("1.Add at front\n2.Add at Rear\n3.Delete from Front\n4.Delete from Rear\n5.Display\n6.Quit\n");
        printf("Enter your choice: ");
        scanf("%d" ,&choice);
        switch(choice)
        {
            case 1: printf("Enter element to add at front: ");
                    scanf("%d" ,&x);
                    addAtFront(q,x,&k,max);
                    break;
            case 2: printf("Enter element to add at rear: ");
                    scanf("%d" ,&x);
                    addAtRear(q,x,&k,max);
                    break;
            case 3: deleteFromFront(q,&k);
                    break;
            case 4: deleteFromRear(q,&k);
                    break;
            case 5: Display(q,k);
                    break;
            case 6: printf("Quiting the program.");
                    return 0;
                    break;
            default:printf("Invalid Choice\n");
                    break;                                  
        }
    }
    return 0;
}