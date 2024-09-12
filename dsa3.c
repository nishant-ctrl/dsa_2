/*
Write a program to store a matrix of names and then print the names contained in the principal diagonal
of the matrix. Take the dimensions of the matrix as input from the user, store names in the matrix
(where the matrix is implemented with a three-dimensional character array) in row-major order so that
each element of the matrix is a name, and then display the list of names contained in the principal
diagonal of the matrix, in the correct order from the top left element to the bottom right element of the
principal diagonal, as the final output of your program.
*/
#include<stdio.h>
int main()
{
    char mat[50][50][50];
    int row,column;
    printf("Enter the size of the matrix in the form row X column : ");
    scanf("%d%d" ,&row,&column);
    getchar();
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<column ; j++)
        {
            printf("Enter element at [%d][%d] : " ,i+1,j+1);
            fgets(mat[i][j] , 50 , stdin);
        }
    }
    int i,j;
    printf("Names at Principal Diagonal:\n");
    for(i=0,j=0 ; (i<row)&&(j<column) ; i++,j++)
    {
        printf("Nmae at [%d][%d] in the matrix: %s\n" ,i+1,j+1,mat[i][j]);
    }
    return 0;
}