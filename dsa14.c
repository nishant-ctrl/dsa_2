#include <stdio.h>
#include <stdlib.h>
int isNumber(char str[])
{
    for(int i=0 ; str[i]!='\0' ; i++)
    {
        if(str[i]<'0' || str[i]>'9')
        {
            return 0;
        }
    }
    return 1;
}
void push(int stack[], int *top, int value)
{
    (*top)++;
    stack[*top] = value;
}

int pop(int stack[], int *top)
{
    int value = stack[*top];
    (*top)--;
    return value;
}

int main(int argc, char *argv[])
{
    int stack[100];
    int top = -1;
    int num=0;
    int operand1, operand2;
    int result;
    char *currentstr;
    for (int i = 1; i < argc; i++)
    {
        currentstr = argv[i];
        // printf("\ncurrent string  %s\n",currentstr);
        if (isNumber(currentstr))
        {
            num=0;
            for (int i = 0; currentstr[i]!='\0'; i++)
            {
                num=num*10+(currentstr[i]-48);
            }
            // printf("\nnum: %d",num);
            push(stack, &top, num);
        }
        else
        {
            operand2 = pop(stack, &top);
            operand1 = pop(stack, &top);
            switch (currentstr[0])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '%':
                result = operand1 % operand2;
                break;
            default:
                printf("Invalid operator: %s\n", currentstr);
                return 1;
            }
            push(stack, &top, result);
        }
    }
    if (top == 0)
    {
        printf("Result: %d\n", stack[top]);
    }
    else
    {
        printf("Error: Invalid postfix expression\n");
    }
    return 0;
}