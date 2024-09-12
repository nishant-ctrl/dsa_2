/*
Write a program to find the sum of the elements of the principal diagonal of a matrix. Take a matrix of
real numbers as input from the user in row-major order, and then print the sum of the principal diagonal
elements of the matrix as the final output of your program. Also, print the elements of the principal
diagonal of the matrix.
*/
#include<stdio.h>
int main()
{
    int mat[50][50];
    int row,column;
    printf("Enter the size of the matrix in the form row X column : ");
    scanf("%d%d" ,&row,&column);
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<column ; j++)
        {
            printf("Enter element at [%d][%d] : " ,i+1,j+1);
            scanf("%d" ,&mat[i][j]);
        }
    }
    int sum=0;
    int i,j;
    printf("Elements at Principal Diagonal:\n");
    for(i=0,j=0 ; (i<row)&&(j<column) ; i++,j++)
    {
        printf("Element at [%d][%d] : %d\n" ,i+1,j+1,mat[i][j]);
        sum+=mat[i][j];
    }
    printf("Sum of elements at principal diagonal: %d" ,sum);
    return 0;
}