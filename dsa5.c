#include <stdio.h>
struct details
{
    char pnr_number[20];
    char name[50];
    int age;
    int seat_number;
};
void book_ticket(char name[100] , int age , int *count , int booked_seat[] , int *bs)
{
    int check=0;
    if(age>60)
    {
        for (int i = 0; i < bs; i++)
        {
            if(booked_seat[i]==3 || booked_seat[i]==6 || booked_seat[i]==9 || booked_seat[i]==12 || booked_seat[i]==15) 
            {
                check++;
            }      
        }
    }
    if(check==5)
    {
        pass[*count].name=name;
        pass[*count].age=age;
        pass[*count].pnr_number=age*9+10;

        pass[*count].seat_number=;
        (*count)++;
    }
    else if(check==1)
    {

    }
 
}
int main()
{
    struct details pass[15];
    int choice;
    int current_pass_count=0;
    char temp_name[100];
    int temp_age;
    int booked_seat[15];
    int bs=0;
    while(1)
    {
        printf("\n\tMENU\t\n");
        printf("1.Book Ticket\n2.Cancel Ticket\n3.Print Ticket\n4.Print Chart\n5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d" ,&choice);
        switch(choice)
        {
            case 1:if(current_pass_count!=10)
                {
                    printf("Sorry ! Tickets are not available.");
                }
                else
                {
                    printf("Enter your name: ");
                    fgets(temp_name , 100 , stdin);
                    printf("Enter your age: ");
                    scanf("%d" , &temp_age);
                    book_ticket(temp_name,temp_age,&current_pass_count,booked_seat,&bs);
                    break;
                }
        }
    }


    return 0;
}