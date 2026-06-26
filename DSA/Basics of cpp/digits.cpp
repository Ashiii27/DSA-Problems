#include<iostream>
using namespace std;

int main() {
    // int n,digit,num;
    // digit = 1;
    // num =10;
    // cout<<"Enter the number :";
    // cin>>n;

    // for(int i = 1;i<=10000;i++)
    // {
    //     if(n/num==0){
    //      cout<<digit;    
    //      return 0; 
    //     }
    //   num= num*10;
    //   digit++;  
        
    // }

    //Now using while loop
     
    // int n;
    // cin>>n;
    // int digit=0;

    // while (n)
    // {
    //     digit++;
    //     n=n/10;
    // }
    
    // cout<<digit;

//------------------------------------------------------------------------------------

//Reversing a number

    // int n;
    // cout<<"Enter the number:";
    // cin>>n;
    // int sum=0;
    // while (n)
    // {
    //     int digit=n%10;
    //     sum=sum*10+digit;
    //     n=n/10;
    // }
    // cout<<sum;

//------------------------------------------------------------------------------------

//Checking for pallindrome

    int n,a;
    cout<<"Enter the number:";
    cin>>n;
    a=n;
    int sum=0;
    while (n)
    {
        int digit=n%10;
        sum=sum*10+digit;
        n=n/10;
    }
    if (a==sum)
    {
    cout<<"yes";
    }
    else cout<<"no";
    
    
    return 0;
}