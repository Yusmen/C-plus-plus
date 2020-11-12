/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2
.020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 3
* @compiler GCC
*
*/


#include<iostream>

using namespace std;

int main()
{

    int number1,number2,number3;

    do
    {
        cin>>number1;
    }
    while(number1<0);

    do
    {
        cin>>number2;
    }
    while(number2<0);

    do
    {
        cin>>number3;
    }
    while(number3<0);

    if(number1==number2 && number1!=0 && number2!=0)
    {
        cout<<number1<<number3<<number1;
        return 0;
    }
    else if (number2==number3&& number2!=0 && number3!=0)
    {
        cout<<number2<<number1<<number3;
        return 0;
    }
    else if (number1==number3 && number1!=0 && number3!=0)
    {
        cout<<number1<<number2<<number1;
        return 0;
    }

    if(number1==number2 && number2==number3 && number1==number3)
    {
        cout<<number1<<number1<<number1;
        return 0;
    }

    if(number1>=number2 && number1>=number3)
    {
        if(number3<=number2)
        {
          if(number3!=0)
           {
             cout<<number3<<number2<<number1<<number2<<number3;
           }
           else if(number2!=0)
           {
               cout<<number2<<number3<<number1<<number3<<number2;
           }
          else
           {
              cout<<number1<<0<<number1;
           }

        }
        else if(number2<=number3)
        {
           if(number2!=0)
           {
             cout<<number2<<number3<<number1<<number3<<number2;
           }
           else if(number3!=0)
           {
               cout<<number3<<number2<<number1<<number2<<number3;
           }
          else
           {
              cout<<number1<<0<<number1;
           }

        }

    }
    else if(number2>=number1 && number2>=number3)
    {
        if(number3<=number1)
        {
             if(number3!=0)
              {
                   cout<<number3<<number1<<number2<<number1<<number3;
              }

            else if(number1!=0)
            {
              cout<<number1<<number3<<number2<<number3<<number1;
            }

             else
             {
                 cout<<number2<<0<<number2;

             }

        }
        else if(number1<=number3)
        {
            if(number1!=0)
            {
               cout<<number1<<number3<<number2<<number3<<number1;
            }
            else if(number3!=0)
            {
                cout<<number3<<number1<<number2<<number1<<number3;
            }
            else
            {
                cout<<number2<<0<<number2;

            }

        }

    }
    else if(number3>=number1 && number3>=number2)
    {
        if(number1<=number2)
        {
            if(number1!=0)
            {
                cout<<number1<<number2<<number3<<number2<<number1;
            }
            else if(number2!=0)
            {
                cout<<number2<<number1<<number3<<number1<<number2;
            }
            else
            {
                cout<<number3<<0<<number3;
            }
        }
        else if(number2<=number1)
        {
            if(number2!=0)
            {
                cout<<number2<<number1<<number3<<number2<<number1;
            }
            else if(number1!=0)
            {
                cout<<number1<<number2<<number3<<number2<<number1;
            }
            else
            {
                cout<<number3<<0<<number3;
            }
        }

    }

}
