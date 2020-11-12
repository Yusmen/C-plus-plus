/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 2
* @compiler GCC
*
*/

#include<iostream>

using namespace std;

int main()
{
    int number;
    int maxNum = -2;
    int secondMaxNum = -2;
    int count = 0;

    while(true)
    {

        cin>>number;
        count++;


        if(number <= 0)
        {
            break;
        }
        if(number > maxNum)
        {
           secondMaxNum = maxNum;
           maxNum = number;
        }
        else if(number > secondMaxNum && number != maxNum)
        {
            secondMaxNum = number;

        }

    }
    if(count<=2)
    {
        cout<<-1;
        return 0;
    }

    if(secondMaxNum==-2)
    {
        cout<<maxNum;
    }
    else
    {
        cout<<secondMaxNum;

    }

}
