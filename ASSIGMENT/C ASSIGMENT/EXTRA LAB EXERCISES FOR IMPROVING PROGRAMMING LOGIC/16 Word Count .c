// Write a C program that counts the number of words in a sentence entered by the user. 
// Challenge: Modify the program to find the longest word in the sentence.
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char str[500],big[500],st;
    int spc=0,num=0,count=0,ncount=0;

    printf("enter a sentence:- ");
    gets(str);

    num=strlen(str);
    for (int i = 0; i<=num; i++)
    {   
        
        if(str[i]==' ')
        spc++;
    }
    spc++;
        
    printf("word is %d",spc);

    
    return 0;
}