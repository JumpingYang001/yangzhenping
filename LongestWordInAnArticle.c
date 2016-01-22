#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
   if( argc != 2 ) {
      printf("Usage: ./LongestWordInAnArticle article1.txt\n");
      return 0;
   }
   char *fileName= argv[1];
   const char *word_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char tempword[100];
   char longestword[100];
   int maxNumber=0;
   FILE *fp;
   int c;
   int n = 0;
   int longestwordindex = 0;
  
   fp = fopen(fileName,"r");
   if(fp == NULL) 
   {
      perror("Error in opening file");
      return(-1);
   }
   do
   {
      c = fgetc(fp);
      if(feof(fp))
      {
         break ;
      }
      if (strchr(word_characters, c) || c=='-')
      {
          tempword[longestwordindex++]=c;
          //printf("%c is in \"%s\"\n", c, word_characters);
      }
      else
      {
          tempword[longestwordindex]='\0';

          if(tempword[0]!='\0')
          {
             if(longestwordindex>=maxNumber)
             {
             maxNumber=longestwordindex;
             strcpy(longestword,tempword);
             //printf("Found %d length: \"%s\"\n",maxNumber, tempword);
             }
          }
          longestwordindex=0;
      }
   }while(1);

   if(maxNumber==0)
   {
      printf("Not found any words!\n");
   }
   else
   {
      printf("Found longest word: \"%s\"\n",longestword);
   }
   fclose(fp);
   return(0);
}