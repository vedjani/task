// #include<stdio.h>
// #include<conio.h>
// int main()
// {
//     float l,w,ans;

//     printf("enter length:-");
//     scanf("%f",&l);
//     printf("enter width:- ");
//     scanf("%f",&w);

//     ans=l*w;

//     printf("area of rectangle = %f",ans);

//     return 0;
// }

//----------------------------------------------------------------------------
#include<iostream>
using namespace std;
class r_area{
public:
    float l,w;

    float area_r()
    {
        
        return l*w;

    }

};
int main()
{
   

    r_area a1;
    
    cout<<"enter length:-";
    cin>>a1.l;
    cout<<"enter width:-";
    cin>>a1.w;

    cout<<"area of rectangle ="<<a1.area_r();



    return 0;
}