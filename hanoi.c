#include <stdio.h>
#define MAX 100
int isEmpty(int top)
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int push(int stack[], int *top, int item)
{
    if (*top >= MAX - 1)
    {
        printf("Stack is full!\n");
        return 0;
    }
    if (!isEmpty(*top) && item > stack[*top])
    {
        printf("Cannot push %d on top of %d\n", item, stack[*top]);
        return 0;
    }
    (*top)++;
    stack[(*top)] = item;
    return 1;
}
int pop(int stack[], int *top, int *item)
{
    if (isEmpty(*top))
    {
        printf("Stack is empty!\n");
        return 0;
    }
    *item = stack[*top];
    (*top)--;
    return 1;
}
void printStack(int stack[], int top)
{
    if (isEmpty(top)==1)
    {
        printf("Stack is Empty");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
}

int isSolved(int top1, int top2, int top3, int n)
{
    return isEmpty(top1) && isEmpty(top2) && top3 == n - 1;
}

void display(int s1[], int top1, int s2[], int top2, int s3[], int top3)
{
    printf("s1: ");
    printStack(s1, top1);
    printf("\ns2: ");
    printStack(s2, top2);
    printf("\ns3: ");
    printStack(s3, top3);
    printf("\n");
}

int main()
{
    int s1[MAX], s2[MAX], s3[MAX];
    int top1 = -1, top2 = -1, top3 = -1;
    int n, moves = 0, element;

    printf("Enter the number of elements in s1: ");
    scanf("%d", &n);

    printf("Enter %d elements for s1 in non-decreasing order (smallest to largest):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &element);
        if (!push(s1, &top1, element))
        {
            printf("Please check order.\n");
            return -1;
        }
    }

    while (1)
    {
        display(s1, top1, s2, top2, s3, top3);
        printf("\nChoose a move:\n");
        printf("1. Move from s1 to s2\n");
        printf("2. Move from s1 to s3\n");
        printf("3. Move from s2 to s1\n");
        printf("4. Move from s2 to s3\n");
        printf("5. Move from s3 to s1\n");
        printf("6. Move from s3 to s2\n");
        printf("7. Quit\n");

        int choice;
        scanf("%d", &choice);

        int *sourceTop, *destTop, *sourceStack, *destStack;
        switch (choice)
        {
        case 1:
            sourceStack = s1;
            sourceTop = &top1;
            destStack = s2;
            destTop = &top2;
            break;
        case 2:
            sourceStack = s1;
            sourceTop = &top1;
            destStack = s3;
            destTop = &top3;
            break;
        case 3:
            sourceStack = s2;
            sourceTop = &top2;
            destStack = s1;
            destTop = &top1;
            break;
        case 4:
            sourceStack = s2;
            sourceTop = &top2;
            destStack = s3;
            destTop = &top3;
            break;
        case 5:
            sourceStack = s3;
            sourceTop = &top3;
            destStack = s1;
            destTop = &top1;
            break;
        case 6:
            sourceStack = s3;
            sourceTop = &top3;
            destStack = s2;
            destTop = &top2;
            break;
        case 7:
            printf("Quitting the GAME.\n");
            return 0;    
        default:
            printf("Invalid choice!\n");
        }

        if (pop(sourceStack, sourceTop, &element))
        {
            if (push(destStack, destTop, element))
            {
                moves++;
                if (isSolved(top1, top2, top3, n))
                {
                    printf("Congratulations! You solved the game in %d moves.\n", moves);
                    break;
                }
            }
            else
            {
                push(sourceStack, sourceTop, element);
            }
        }
    }

    return 0;
}
