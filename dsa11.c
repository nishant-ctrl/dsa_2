#include <stdio.h>
int push(int stack[], int *top, int value)
{
    if (*top == 100 - 1)
    {
        printf("Stack overflow\n");
        return 0;
    }
    if (*top != -1 && stack[*top] < value)
    {
        printf("Invalid move: Can't push %d on top of %d\n", value, stack[*top]);
        return 0;
    }
    (*top)++;
    stack[*top] = value;
    return 1;
}
int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Invalid move: Stack is empty\n");
        return -1;
    }
    int item=stack[*top];
    (*top)--;
    return item;
}
void display_stacks(int s1[], int top1, int s2[], int top2, int s3[], int top3)
{
    printf("s1: ");
    for (int i = top1; i >= 0; i--)
    {
        printf("%d ", s1[i]);
    }
    printf("\ns2: ");
    for (int i = top2; i >= 0; i--)
    {
        printf("%d ", s2[i]);
    }
    printf("\ns3: ");
    for (int i = top3; i >= 0; i--)
    {
        printf("%d ", s3[i]);
    }
    printf("\n");
}
int is_game_solved(int top3, int n)
{
    if(top3==n-1)
    {
        return top3 == n - 1;
    }
    return 0;
}

int main()
{
    int n, moves = 0;
    int s1[100], s2[100], s3[100];
    int top1 = -1, top2 = -1, top3 = -1;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    for (int i = n; i > 0; i--)
    {
        top1++;
        s1[top1] = i;
    }
    int *source_stack = NULL, *dest_stack = NULL;
    int *source_top = NULL, *dest_top = NULL;
    int choice, element;
    while (1)
    {
        printf("\nCurrent stacks:\n");
        display_stacks(s1, top1, s2, top2, s3, top3);
        printf("\nMenu:\n1. Move from s1 to s2\n2. Move from s1 to s3\n3. Move from s2 to s1\n");
        printf("4. Move from s2 to s3\n5. Move from s3 to s1\n6. Move from s3 to s2\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            source_stack = s1;
            source_top = &top1;
            dest_stack = s2;
            dest_top = &top2;
            break;
        case 2:
            source_stack = s1;
            source_top = &top1;
            dest_stack = s3;
            dest_top = &top3;
            break;
        case 3:
            source_stack = s2;
            source_top = &top2;
            dest_stack = s1;
            dest_top = &top1;
            break;
        case 4:
            source_stack = s2;
            source_top = &top2;
            dest_stack = s3;
            dest_top = &top3;
            break;
        case 5:
            source_stack = s3;
            source_top = &top3;
            dest_stack = s1;
            dest_top = &top1;
            break;
        case 6:
            source_stack = s3;
            source_top = &top3;
            dest_stack = s2;
            dest_top = &top2;
            break;
        case 7:
            printf("Game exited.\n");
            return 0;
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
        element = pop(source_stack, source_top);
        if (element != -1)
        {
            if (push(dest_stack, dest_top, element))
            {
                moves++;
            }
            else
            {
                printf("Move failed. Returning disk to original stack.\n");
                push(source_stack, source_top, element); // Put back the disk on the original stack
            }
        }
        if (is_game_solved(top3, n))
        {
            printf("\nCongratulations! You solved the game in %d moves.\n", moves);
            break;
        }
    }
    return 0;
}
