/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Yusmen Zabanov
* @idnumber 62556
* @task 1
* @compiler GCC
*
*/


#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int N,X,M;

    cin>>N;
    cin>>X;
    cin>>M;

    int oddSum=0;
    int evenSum=0;

    if(N%2==0)
    {

        for(int i=1;i<=N/2;i++)
        {
            oddSum+=M;
            evenSum+=i*30-5;
        }
    }
    else
    {

        for(int i=1;i<=N/2-1;i++)
        {
            evenSum+=i*30-5;
        }

        for(int i=1;i<=N/2+1;i++)
        {
            oddSum+=i*30-5;
        }
    }
    int result=(oddSum+evenSum)-X;

    if(result>0)
    {
        cout<<"yes"<<endl;
        cout<<result;
    }
    else
    {
        cout<<"no"<<endl;
        cout<<abs(result);
    }


}
