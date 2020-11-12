/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 5
* @compiler GCC
*
*/


#include<iostream>
#include<cmath>

 using namespace std;

 int main()
 {

    int n;
    int divisorNumber=1;
    int count=0;

    do
    {
        cin>>n;
    }
    while(n<2||n>pow(10,9));


    int tempN=0;
    tempN=n;
    while(tempN!=0)
    {

        count++;
        tempN/=10;
    }

    divisorNumber=divisorNumber*pow(10,count-1);

    for(int i=0;i<n-1;i++)
    {
        if(divisorNumber==n)
        {
            cout<<i+count-1;
            return 0;
        }
        divisorNumber*=10;
        divisorNumber=divisorNumber%n;
        if(divisorNumber==0)
        {
            cout<<count+i;
            return 0;
        }

    }
    cout<<"NO";

 }
