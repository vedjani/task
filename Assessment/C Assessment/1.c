#include <stdio.h>
#include <string.h>

void reverseString(char str[]) 
{
    int len = strlen(str);
    printf("Reversed: ");
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void checkPalindrome(char str[]) 
{
    int len = strlen(str), flag = 1;
    for (int i = 0; i < len/2; i++) 
    {
        if (str[i] != str[len - i - 1]) 
        {
            flag = 0; 
            break;
        }
    }
    if (flag)
    { 
        printf("Palindrome\n");
    }
    else 
    {
        printf("Not Palindrome\n");
    }
}

void copyString(char str[]) 
{
    char copy[100];
    strcpy(copy, str);
    printf("Copied string: %s\n", copy);
}

void lengthString(char str[]) 
{
    printf("Length: %d\n", (int)strlen(str));
}

void countVowelsConsonants(char str[]) 
{
    int v = 0, c = 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        char ch = str[i];
    
        if (ch >= 'A' && ch <= 'Z') 
        {
            ch = ch + 32;
        }
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') 
        {
            v++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            c++;
        }
    }
    printf("Vowels = %d, Consonants = %d\n", v, c);
}

void countBlanksDigits(char str[]) 
{
    int blanks = 0, digits = 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] == ' ')
        { 
            blanks++;
        }
        if (str[i] >= '0' && str[i] <= '9') 
        {
            digits++;
        }
    }
    printf("Blanks = %d, Digits = %d\n", blanks, digits);
}

int main() 
{
    char str[100], str2[100];
    int choice;
    char count;

    do {
        printf("\nEnter a string: ");
        scanf(" %[^\n]", str);

        printf("\n--- MENU ---\n");
        printf("1. Reverse\n");
        printf("2. Concatenate\n");
        printf("3. Palindrome\n");
        printf("4. Copy\n");
        printf("5. Length\n");
        printf("6. Vowels & Consonants\n");
        printf("7. Blanks & Digits\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
            {
            reverseString(str); 
            break;
            }
            case 2: 
            {
                printf("Enter another string: ");
                scanf(" %[^\n]", str2);
                strcat(str, str2);
                printf("Concatenated: %s\n", str);
                break;
            }
            case 3: 
            {
                checkPalindrome(str); 
                break;
            }
            case 4: 
            {
                copyString(str); 
                break;
            }
            case 5: 
            {
                lengthString(str); 
                break;
            }
            case 6: 
            {
                countVowelsConsonants(str); 
                break;
            }
            case 7: 
            {
                countBlanksDigits(str); 
                break;
            }
            default:
            {
                printf("Invalid choice!\n");
            }
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &count);

    } while(count=='y' || count=='Y');

    printf("Program ended.\n");
    return 0;
}