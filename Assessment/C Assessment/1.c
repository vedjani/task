#include <stdio.h>
#include <string.h>

void revStr(char str[])
{
    int len = strlen(str);
    printf("Reversed: ");
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void checkpalindrome(char str[])
{
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            printf("\nNot Palindrome");
            return;
        }
        i++;
        j--;
    }
    printf("Palindrome\n");
}

void copyStr(char str[])
{
    char copy[100];
    puts(str);
    strcpy(copy,str);
    printf("Copied string: %s\n", copy);
}

void lenStr(char str[])
{
    printf("Length: %d\n", (int)strlen(str));
}

void vowelsconsonants(char str[])
{
    int v = 0, c = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
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

void countspace(char str[])
{
    int space = 0, digits = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            space++;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
    }
    printf("Space = %d, Digits = %d\n", space, digits);
}

int main()
{
    char str[100], str2[100];
    int choice;
    char option;

    do
    {
        printf("\nEnter a string: ");
        fgets(str, sizeof(str), stdin);
        
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
        getchar();

        switch (choice)
        {
        case 1:
        {
            revStr(str);
            break;
        }
        case 2:
        {
            printf("Enter another string: ");
            gets(str2);
            strcat(str, str2);
            printf("Concatenated: %s\n", str);
            break;
        }
        case 3:
        {
            checkpalindrome(str);
            break;
        }
        case 4:
        {
            copyStr(str);
            break;
        }
        case 5:
        {
            lenStr(str);
            break;
        }
        case 6:
        {
            vowelsconsonants(str);
            break;
        }
        case 7:
        {
            countspace(str);
            break;
        }
        default:
        {
            printf("\nInvalid choice!");
        }
        }

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &option);
        getchar();

    } while (option== 'y' || option == 'Y');

    return 0;
} 