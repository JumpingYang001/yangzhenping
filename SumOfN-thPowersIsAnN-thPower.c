#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[])
{
    long int list[75];
    int i,a,b,c,d,e,f;
    for(i=1;i<=75;i++)
    {
       list[i-1]=(long int)pow(i,5);
       //printf("%ld\n", list[i-1]);
    }

    for(a=1;a<=75;a++)
    {
       for(b=a;b<=75;b++)
       {
          for(c=b;c<=75;c++)
          {
             for(d=c;d<=75;d++)
             {
                for(e=d;e<=75;e++)
                {
                   for(f=e;f<=75;f++)
                   {
                      if(list[a-1]+list[b-1]+list[c-1]+list[d-1]+list[e-1]==list[f-1])
                      {
                         printf("A=%d,B=%d,C=%d,D=%d,E=%d,F=%d\n",a,b,c,d,e,f);
                         break;
                      }
                   }
                }
             }
          }
       }
    }
    
    return 0;
}