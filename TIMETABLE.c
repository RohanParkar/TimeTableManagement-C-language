#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,i,j,c,k;float t,s,m;

FILE *f;
char day[10][10]={"         ","monday   ","tuesday  ","wednesday","thursday ","friday   ","saturday ","sunday   "};
struct day
{
int timef[20];
int timet[20];
char sub[20][20];
}d[7];
void newtt();
void printtt();
void viewspec();

//-------------------------------------------------------------------------------------------------------------------------------------
void main()
{
int x;


printf ("TIME \t TABLE \t SCHEDULING\n");
do
{
printf ("MENU\n1.NEW\n2.VIEW\n3.VIEW SPECIFIC\n4.QUIT\n");
scanf("%d",&x);
switch(x)
{
case 1:
 newtt();
break;
case 2:
printtt();
break;
case 3:
viewspec();
break;
case 4:
exit(0);
break;
default:
printf ("enter your choice\n");
}
}while(x!=4);

}
//-------------------------------------------------------------------------------------------------------------------------------------
void newtt()
{
float t=9.00;

f=fopen("timetable.txt","w+");

if(f==NULL)
{
printf("error");

}
else
{
  for(i=1;i<8;i++)
  {
  float t=9.00;
 printf("ENTER FOR %s\n",day[i]);
  
   for(j=0;j<8;j++)
         {
            
             printf("enter task or subject for %.2f to %.2f\n",t,t+1);
             scanf("%s",&d[i].sub[j]);
             t++;
            fprintf(f,"%s\n",d[i].sub[j]);
             } 
   }
 } 

fclose(f);

}
//-------------------------------------------------------------------------------------------------------------------------------------
void printtt()
{

f=fopen("timetable.txt","r");

if(f==NULL)
{
printf("error");

}
else
{
 for(i=0;i<8;i++)
 {
 float t=9.00;
 printf("%s\t",day[i]);
             if(i==0)   
                  {
                   for(k=0;k<8;k++) 
                   {
                   printf("%.2f to %.2f  ",t,t+1);
                   t++;
	           }
                  } 
             else
                 {
                    for(j=0;j<8;j++)
                       {                
		             fscanf(f,"%s\n",&d[i].sub[j]);      
                             printf("%s",d[i].sub[j]);
                             s=strlen(d[i].sub[j]);
                               for(m=1;m<=16-s;m++)
                                      printf(" ");
                       }
                 printf("\n");
                 }  
       
   } 

} 


fclose(f);

}
//-------------------------------------------------------------------------------------------------------------------------------------
void viewspec()
{
printf ("\n1.MONDAY\n2.TUESDAY\n3.WEDNESDAY\n4.THURSDAY\n5.FRIDAY\n6.SATURDAY\n7.SUNDAY\n");
scanf("%d",&c);
   printf(" for %s\n",day[c]);
f=fopen("timetable.txt","r");

if(f==NULL)
{
printf("error");
}
else
{
 for(i=0;i<8;i++)
 {
 float t=9.00;
 		for(j=0;j<8;j++)
                       {                
		            fscanf(f,"%s\n",&d[i].sub[j]);      
                                if(i==c)
                                {
                                      
				    
                                       printf("%.2f to %.2f\t",t,t+1);
                                    
                                       printf("%s\n",d[i].sub[j]);
                                       t++;
	                              
                  
                                }
                       }
                
                   
       
   } 

} 


fclose(f);
}
//------------------------------------------------------------------------------------------------------------------------------------- 




