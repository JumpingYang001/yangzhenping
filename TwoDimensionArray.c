#include <stdio.h>
#include <math.h>

#define red   "\033[0;31m"        /* 0 -> normal ;  31 -> red */
#define backgroundblack   "\033[7;30m"        /* http://cc.byexamples.com/2007/01/20/print-color-string-without-ncurses/ */
#define cyan  "\033[1;36m"        /* 1 -> bold ;  36 -> cyan */
#define green "\033[4;32m"        /* 4 -> underline ;  32 -> green */
#define blue  "\033[9;34m"        /* 9 -> strike ;  34 -> blue */
 
#define black  "\033[0;30m"
#define brown  "\033[0;33m"
#define magenta  "\033[0;35m"
#define gray  "\033[0;37m"
 
#define none   "\033[0m"        /* to flush the previous property */

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
          if(list[i-1][j-1]==0)
             printf("%s%d\t%s", black, list[i-1][j-1], black);
          else 
             printf("%s%d\t%s", backgroundblack, list[i-1][j-1], backgroundblack);
       }
       printf("%s\n%s", black, black);
    }

    return 0;
}