#include "stdafx.h"
#include<iostream>
using namespace std;
void ArrIn(int* arr, int n);
void ArrOut(int* arr, int n);
void EvenNumbers(int* arr, int n);
void SortArr(int* arr, int n);
int main()
{
	int n;
	cout << "Amount of numbers: "; cin >> n;
	int* arr = new int[n];
	ArrIn(arr, n);
	ArrOut(arr, n);
	cout << "Only even numbers:" << endl;
	EvenNumbers(arr, n);
	SortArr(arr, n);
	cout << "Sorted array" << endl;
	ArrOut(arr, n);
	delete[] arr;
}
void ArrIn(int* arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> *(arr + i);
	}
}
void ArrOut(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << endl;
	}
}
void EvenNumbers(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (*(arr + i) % 2 == 0)
		{
			cout << *(arr + i) << endl;
		}
	}
}
void SortArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int max = *(arr+i);
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (*(arr+j) > max)
			{
				max = *(arr+j);
				index = j;
			}
		}
		*(arr+index) = *(arr+i);
		*(arr+i) = max;
	}
}
