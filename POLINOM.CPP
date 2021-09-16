#include<iostream>
#include<string>
#include<math.h>
using namespace std;

struct Element
{
	double koef;
	int pow;
	Element* link;
};

class List
{

private:
	Element* field;
	int length;

public:
	void Push(double k, int s);
	List();
	void Print();
	bool isEmpty();
	int FindValue(int x);
	void SumPolynoms(List firstPolyom, List secondPolynom);
	int getLength();
	Element* getFileld();
	void SubtractPolynoms(List firstPolynom, List secondPolynom);
	void RemoveRep();
	void MultiplyEdnochlen(List endnochlen, List polynom);
	void MultiplyMnogochlen(List firstPolynom, List secondPolynom);
	void Sort();

};
List::List()
{
	this->field = NULL;
	this->length = 0;
}
void List::Push(double k, int s)
{

	if (k != 0)
	{

		if (isEmpty())
		{
			Element* p = new Element;
			p->koef = k;
			p->pow = s;
			p->link = NULL;
			this->field = p;
			this->length++;

		}
		else
		{

			Element* h = this->field;

			while (h->link != NULL)
			{
				h = h->link;

			}
			Element* p = new Element;
			p->koef = k;
			p->pow = s;
			p->link = NULL;
			h->link = p;
			this->length++;


		}

	}
}
bool List::isEmpty()
{
	return this->length == 0;
}

void List::Print()
{

	Element* temp = this->field;
	for (int i = 0; i < this->length; i++)
	{

		if (temp->pow == 0)
		{
			if (i == this->length - 1 && temp->koef != 0)
			{
				cout << temp->koef;
			}
			else
			{
				if (temp->koef != 0)
				{
					cout << temp->koef;
					if (temp->link->koef > 0)
					{
						cout << "+";
					}
				}
			}
		}
		else if (temp->pow == 1)
		{
			if (i == this->length - 1 && temp->koef != 0)
			{
				cout << temp->koef;
				cout << "x";
			}
			else
			{
				if (temp->koef != 0)
				{
					cout << temp->koef;
					cout << "x";
					if (temp->link->koef > 0)
					{
						cout << "+";

					}
				}
			}
		}

		else if (i == this->length - 1 && temp->koef != 0)
		{
			cout << temp->koef;
			cout << "x";
			cout << "^";
			cout << temp->pow;
		}

		else if (temp->koef != 0)
		{
			if (temp->koef == 1)
			{
				cout << "x";
				cout << "^";
				cout << temp->pow;
			}
			else
			{
				cout << temp->koef;
				cout << "x";
				cout << "^";
				cout << temp->pow;
			}

			if (temp->link->koef > 0)
			{
				cout << "+";

			}
		}

		temp = temp->link;


	}
	cout << endl;

}

int List::FindValue(int x)
{
	int result = 0;
	Element* temp = this->field;

	for (int i = 0; i < this->length; i++)
	{

		result += temp->koef * pow(x, temp->pow);
		temp = temp->link;
	}

	return result;

}
int List::getLength()
{
	return this->length;
}
Element* List::getFileld()
{
	return this->field;
}
void List::SumPolynoms(List firstPolynom, List secondPolynom)
{

	Element* firstTemp = firstPolynom.getFileld();
	Element* secondTemp = secondPolynom.getFileld();

	while (firstTemp != NULL)
	{

		while (secondTemp != NULL)
		{

			if (firstTemp->pow == secondTemp->pow)
			{

				firstTemp->koef = firstTemp->koef + secondTemp->koef;
				break;

			}

			secondTemp = secondTemp->link;

		}

		firstTemp = firstTemp->link;

	}

}
void List::SubtractPolynoms(List firstPolynom, List secondPolynom)
{

	Element* firstTemp = firstPolynom.getFileld();
	Element* secondTemp = secondPolynom.getFileld();



	while (firstTemp != NULL)
	{

		while (secondTemp != NULL)
		{

			if (firstTemp->pow == secondTemp->pow)
			{
				int result = firstTemp->koef - secondTemp->koef;


				firstTemp->koef = result;
				break;

			}

			secondTemp = secondTemp->link;

		}

		firstTemp = firstTemp->link;

	}

}
void List::RemoveRep()
{

	Element* temp = this->field;

	while (temp->link != NULL)
	{

		Element* secondTemp = temp->link;
		Element* secondTempBefore = temp;
		int firstPow = temp->pow;

		while (secondTemp->link != NULL)
		{
			if (secondTemp->pow == firstPow)
			{
				temp->koef += secondTemp->koef;
				Element* del = secondTemp;
				secondTempBefore = del->link;
				delete del;
				//this->length--;
			}

			secondTemp = secondTemp->link;
			secondTempBefore = secondTempBefore->link;

		}

		temp = temp->link;

	}
}
void List::Sort()
{
	Element* firstTemp = this->field;

	while (firstTemp->link != NULL)
	{
		int powToCopmare = firstTemp->pow;
		Element* secondTemp = firstTemp->link;

		while (secondTemp != NULL)
		{
			if (secondTemp->pow > powToCopmare)
			{
				int first = secondTemp->koef;
				secondTemp->koef = firstTemp->koef;
				firstTemp->koef = first;

				int second = secondTemp->pow;
				secondTemp->pow = firstTemp->pow;
				firstTemp->pow = second;
			}
			secondTemp = secondTemp->link;
		}
		firstTemp = firstTemp->link;
	}
}
void List::MultiplyEdnochlen(List endnochlen, List polynom)
{

	Element* firstTemp = endnochlen.getFileld();
	Element* secondTemp = polynom.getFileld();
	int coeficient = firstTemp->koef;
	int pow = firstTemp->pow;

	while (secondTemp != NULL)
	{
		secondTemp->koef *= coeficient;
		secondTemp->pow += pow;
		secondTemp = secondTemp->link;
	}
}
void List::MultiplyMnogochlen(List firstPolynom, List secondPolynom)
{
	Element* firstTemp = firstPolynom.getFileld();


	while (firstTemp != NULL)
	{
		Element* secondTemp = secondPolynom.getFileld();
		int coeficient = firstTemp->koef;
		int pow = firstTemp->pow;

		while (secondTemp != NULL)
		{
			Push(secondTemp->koef * coeficient, secondTemp->pow + pow);
			secondTemp = secondTemp->link;

		}

		firstTemp = firstTemp->link;
	}

}
void Input(List& polynom);
int main()
{

	List l;
	Input(l);
	l.Print();

	l.RemoveRep();
	l.Print();
}
void Input(List& polynom)
{

	int coeficient;
	int pow;
	cout << "Coeficient: ";

	while (cin >> coeficient)
	{
		cout << "Pow: ";
		cin >> pow;
		polynom.Push(coeficient, pow);
		cout << "Coeficient: ";
	}
}
