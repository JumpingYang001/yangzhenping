#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[])
{
    int list[10][10];
    int i,j;
    for(i=1;i<=10;i++)
    {
       for(j=1;j<=10;j++)
       {
          list[i-1][j-1]=0;
       }
    }

    list[0][9]=2;
    list[1][3]=1;
    list[1][4]=1;
    list[1][9]=2;
    list[3][4]=5;
    list[3][7]=3;
    list[4][3]=6;
    list[4][7]=3;
    list[5][7]=3;
    list[5][8]=3;
    list[6][4]=4;
    list[6][5]=4;

    for(i=1;i<=10;i++)
    {
       for(j=1;j<=10;j++)
       {
          printf("%d\t", list[i-1][j-1]);
       }
       printf("\n");
    }

    return 0;
}