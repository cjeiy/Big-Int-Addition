#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <cmath>
#include "function.h"

int main() {

   temp * curr1, * head;
   printf("Press Enter to Start, Press ctrl+d to quit the program");
   char c = getchar();   
   while (c != EOF){
      
      int sum, co=0,i=0,len1,len2,highest;
      char tal1[500],tal2[500];
      head = NULL;

      printf("Ange tal 1: ");
      scanf("%s",tal1);
      c = tal1[0];
      
      printf("Ange tal 2: ");
      scanf("%s",tal2);
      c = tal2[0];

      len1 = strlen(tal1);
      len2 = strlen(tal2);
      
      highest = fmax(len1, len2);



      while ((i+1<=len1) || (i+1<=len2)|| (co==1)){
         
         int k = tal1[len1-1-i] - '0';
         if (i>=len1)
            k=0;

         int j = tal2[len2-1-i] - '0';
         if (i>=len2)
            j=0;

         sum=co+k+j;
         if (sum>=10){
            co=1;
            sum-=10;
         }
         
         else
            co = 0;
         
         curr1 = (temp *)malloc(sizeof (temp));
         curr1->val = sum;
         curr1->next  = head;
         head = curr1;
         
         i+=1;
      }
      curr1 = head;
      FILE *f;
      f = fopen("resultat.txt","a+");
      printf("The Result is: ");
      
      while(curr1) {
         printf( "%d", curr1->val);
         fprintf(f, "%d", curr1->val);
         free(curr1);
         curr1 = curr1->next ;
      } 
      fprintf(f, "\n");
      
      fclose(f);
      printf("\n");
       }
}