#include<stdio.h>
void remove_new_line_char(char arr[])
{
    for(int i=0;arr[i]!='\0';i++)
    {
        if(arr[i]=='\n')
        {
            arr[i]=arr[i+1];
        }
    }
}
struct mynode 
{
    char name[100];
    int run_in_1st_ing;
    int run_in_2nd_ing;
    
};
int main()
{
    struct mynode A[100],I[100];
    int no_of_player=3;
    int total_run_by_A_1st_ing=0;
    int total_run_by_A_2nd_ing=0;
    int total_run_by_A=0;
    int total_run_by_I__1st_ing=0;
    int total_run_by_I__2nd_ing=0;
    int total_run_by_I=0;
    printf("Enter Detail of Australia----->\n");
    for(int i=1;i<=no_of_player;i++)
    {
        printf("Enter name of %d player:",i);
        fgets(A[i].name,100,stdin);
        remove_new_line_char(A[i].name); 
        printf("Enter score in first inning by %d player:",i);
        scanf("%d",&A[i].run_in_1st_ing);
        total_run_by_A_1st_ing=total_run_by_A_1st_ing+A[i].run_in_1st_ing;
        printf("Enter score in second inning by %d player:",i);
        scanf("%d",&A[i].run_in_2nd_ing);
        total_run_by_A_2nd_ing=total_run_by_A_2nd_ing+A[i].run_in_2nd_ing;
        getchar();
    }
    printf("Enter Detail of Indain Team---->\n");
    for(int i=1;i<=no_of_player;i++)
    {
        printf("Enter name of %d player:",i);
        fgets(I[i].name,100,stdin);
        remove_new_line_char(I[i].name);
        printf("Enter score in first inning by %d player:",i);
        scanf("%d",&I[i].run_in_1st_ing);
        total_run_by_I__1st_ing=total_run_by_I__1st_ing+I[i].run_in_1st_ing;
        printf("Enter score in second inning by %d player:",i);
        scanf("%d",&I[i].run_in_2nd_ing);
        total_run_by_I__2nd_ing=total_run_by_I__2nd_ing+I[i].run_in_2nd_ing;
        getchar();
    }
    printf("_____________________________________________________\n");
    printf("SCOREBOARD OF AUSTRALIA--->\n");
    printf("NAME--->Run in 1st ing--->Run in 2nd ing\n");
    for(int i=1;i<=no_of_player;i++)
    {
        printf("%s--->%d--->%d\n",A[i].name,A[i].run_in_1st_ing,A[i].run_in_2nd_ing);
    }
    printf("___________________________________________________________________\n");
    printf("Runs---->%d---->%d\n",total_run_by_A_1st_ing,total_run_by_A_2nd_ing);
    printf("\n\n\n");
    printf("___________________________________________\n");
    printf("SCOREBOARD OF INDIA--->\n");
    printf("NAME--->Run in 1st ing--->Run in 2nd ing\n");
    for(int i=1;i<=no_of_player;i++)
    {
        printf("%s--->%d--->%d\n",I[i].name,I[i].run_in_1st_ing,I[i].run_in_2nd_ing);
    }
    printf("___________________________________________________________________\n");
    printf("Runs---->%d---->%d\n",total_run_by_I__1st_ing,total_run_by_I__2nd_ing);
    total_run_by_A=total_run_by_A_1st_ing+total_run_by_A_2nd_ing;
    total_run_by_I=total_run_by_I__1st_ing+total_run_by_I__2nd_ing;
    if(total_run_by_A>total_run_by_I)
    {
        printf("AUSTRALIA IS WINNER AND WIN BY---> %d run",(total_run_by_A-total_run_by_I));
    }
    else
    {
        printf("INDIA IS WINNER AND WIN BY ---> %d run",(total_run_by_I-total_run_by_A));
    }
}