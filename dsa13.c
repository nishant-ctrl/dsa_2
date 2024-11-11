#include <stdio.h>
void push(char s[], char x, int *index)
{
    (*index)++;
    s[*index] = x;
}
void pop(char s[], int *index)
{
    (*index)--;
}

int main(int argc, char *argv[])
{
    char s[100];
    int k = 0;
    int index = -1;
    for (int i = 1; i < argc; i++)
    {
        printf("\nCURRENT ELEMENT : %c\n", argv[i][0]);
        if (argv[i][0] == '(' || argv[i][0] == '{' || argv[i][0] == '[')
        {
            push(s, argv[i][0], &index);
        }
        else if (argv[i][0] == ')')
        {
            if (index == -1 || s[index] != '(')
            {
                printf("Not Matched\n");
                return 0;
            }
            pop(s, &index);
        }
        else if (argv[i][0] == '}')
        {
            if (index == -1 || s[index] != '{')
            {
                printf("Not Matched\n");
                return 0;
            }
            pop(s, &index);
        }
        else if (argv[i][0] == ']')
        {
            if (index == -1 || s[index] != '[')
            {
                printf("Not Matched\n");
                return 0;
            }
            pop(s, &index);
        }
    }
    if (index == -1)
    {
        printf("Brackets Matched");
    }
    else
    {
        printf("Not Matched");
    }
    return 0;
}