#include<stdio.h>
#include<conio.h>
#include<string.h>

struct hr
{
    char pass[16];
    char tpass[16];
}h1;

struct emp
{
    int id;
    char name[23]; 
}e1[4];

struct intr
{
    int id;
    char name[23]; 
    int months;
}i1[4];

int main()
{   

    struct hr h1={"ved123","T123"};
    struct emp e1[4]={{101,"ved"},{102,"dev"},{103,"rushi"},{104,"mukesh"}};
    struct intr i1[4]={{101,"harsh",6},{102,"abhay",12},{103,"dhruv",10},{104,"kishan",1}};
    


    int dnum,cnum;
    int enu;
    char npass[16],tcpass[16];
    printf("Which Deparment you want to check?");
    printf("\n1 for HR");
    printf("\n2 for TECH \n:-");
    scanf("%d",&dnum);

    switch (dnum)
    {
    case 1:
        printf("you select HR");
        printf("Enter HR password:- ");
        scanf("%s",npass);

        if (strcmp(npass,h1.pass)==0)
        {
            printf("for all data type 1\nfor one data type 2\n:-");
            scanf("%d",&cnum);
            switch(cnum)
            {
                case 1:
                    printf("ID\tNAME\n");
                    for(int i=0;i<4;i++)
                    {
                        printf("\n%d\t%s",e1[i].id,e1[i].name);
                    }
                    break;
                    
                case 2:
                    printf("for which emp you need to check detail enter id :-");
                    scanf("%d",&enu);
            
                    if (e1[enu-101].id==enu)
                    {
                      printf("ID\tNAME\n");
                      printf("\n%d\t%s",e1[enu-101].id, e1[enu-101].name);
                    }
                    else
                    {
                        printf("user not exist");
                    }
                    break;
                default:
                    printf("enter valid number");
                    break;
            }
        }
        else
        {
           printf("password sacho nakho");
        }
        
        break;
        
    case 2:
     printf("you select Tech");
     printf("Enter Tech password:- ");
     scanf("%s",tcpass);

        if (strcmp(tcpass,h1.tpass)==0)
        {
         printf("for all data type 1\nfor one data type 2\n:-");
         scanf("%d",&cnum);
           switch(cnum)
            {
                case 1:
                    printf("ID\tNAME\tMONTHS\n");
                    for(int i=0;i<4;i++)
                    {
                        printf("\n%d\t%s\t%d",i1[i].id,i1[i].name,i1[i].months);
                    }
                    break;
                    
                case 2:
                    printf("for which interns you need to check detail enter id :-");
                    scanf("%d",&enu);

                    if (i1[enu-101].id==enu)
                        {
                             printf("ID\tNAME\tMONTHS\n");
                             printf("\n%d\t%s\t%d",i1[enu-101].id, i1[enu-101].name,i1[enu-101].months);
                         }
                    else
                    {
                        printf("user not exist");
                    }
                    break;
                default:
                    printf("enter valid number");
                    break;
            } 
        }
        else
            {
             printf("password sacho nakho");
            }
        
        break;
    default:
        printf("error...");
        break;
    }






    return 0;
}