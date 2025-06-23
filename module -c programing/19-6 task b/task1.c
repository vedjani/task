
// ✅ Prime Number Check Karne ki Steps:
// User se number lo.
// Check karo ki wo number 1 hai ya nahi.
// Agar 1 hai to wo Prime nahi hota.
// Check karo ki wo number 2 se lekar (number - 1) tak kisi number se divide hota hai ya nahi.
// Agar divide hota hai to Prime nahi hai.
// Agar kisi se divide nahi hota to Prime hai.
#include<stdio.h>
#include<conio.h>
int main()
{
    int num,one=1;

    if (num<=1)
    {
        one=0;
    }
    else
    {
        for (int i = 2; i < num; i++)
        {
            if (num%i==0)
            {
                printf("this number is prime");
            }
            else
            {
                printf("this is not prime");
            }
            
            
        }
        
    }
    
    
    
    
    return 0;
}
