/**
*
* sumolution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 4
* @compiler GCC
*
*/


#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n,number1=1,number2=1,number3=1;
    int sum=0;
    int tempN=0;

    do
    {
        cin>>n;
    }
    while(n<1||n>pow(10,9));

    if(n==4)
    {
        cout<<1<<" "<<2<<" "<<2;
        return 0;
    }
    if(n==6)
    {
        cout<<1<<" "<<2<<" "<<3;
        return 0;
    }

    if(n==0)
    {
        cout<<0<<" "<<0<<" "<<0;
        return 0;
    }

    sum=n;

    bool isPrime=true;

    for(int k=2;k<=n/2;k++)
    {
        if(n%k==0)
        {
             isPrime=false;
             break;

        }

    }
    if(isPrime)
    {
        cout<<1<<" "<<1<<" "<<n;
        return 0;
    }

    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            tempN=n/i;
        }


        for(int j=1;j<=tempN;j++)
        {
            if(tempN%j==0)
            {
                if(i!=j&&((tempN/j)!=j)&&(i+j+tempN/j)<sum)
                {
                      number1=i;
                      number2=j;
                      number3=tempN/j;
                      sum=number1+number2+number3;
                }

            }
        }

    }

    if(number1>=number2&&number1>=number3)
    {
        if(number2>=number3)
        {
             cout<<number3<<" "<<number2<<" "<<number1;
        }
        else
        {
             cout<<number2<<" "<<number3<<" "<<number1;
        }

    }
    else if(number2>=number1&&number2>=number3)
    {
        if(number1>=number3)
        {
            cout<<number3<<" "<<number1<<" "<<number2;
        }
        else
        {
            cout<<number1<<" "<<number3<<" "<<number2;
        }
    }
    else if(number3>=number1&&number3>=number2)
    {
        if(number1>=number2)
        {
            cout<<number2<<" "<<number1<<" "<<number3;
        }
        else
        {
              cout<<number1<<" "<<number2<<" "<<number3;
        }
    }



}
