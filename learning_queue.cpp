#include<iostream>
#include<fstream>
using namespace std;
struct Element
{
	int value;
	Element* next;
};
class Queue
{
private:
	Element* qfront;
	Element* qback;
	int sz;
public:
	Queue();
	void push(int x);
	void pop();
	int queue_front();
	int queue_back();
	int queue_size();
	bool isEmpty();

};
Queue::Queue()
{
	this->qfront = 0;
	this->qback = 0;
	this->sz = 0;
}
void Queue::push(int x)
{
	if (this->sz == 0)
	{
		Element* p = new Element;
		p->value = x;
		p->next = 0;
		this->qfront = p;
		this->qback = p;
		sz++;
	}
	else
	{

		Element* p = new Element;
		p->value = x;
		p->next = 0;
		this->qback->next = p;
		this->qback = p;
		sz++;

	}
}
void Queue::pop()
{
	if (this->sz == 0)
	{
		cout << "Queue is empty!!";
	}
	else
	{
		Element* p = this->qfront;
		this->qfront = this->qfront->next;
		delete p;
		sz--;
	}
}
int Queue::queue_front()
{
	return this->qfront->value;
}
int Queue::queue_back()
{
	return this->qback->value;
}
int Queue::queue_size()
{
	return this->sz;
}
bool Queue::isEmpty()
{
	if (this->sz > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void Input(Queue& q1, char filename[50]);
void Output(Queue q1);
void Operations(Queue q1, Queue q2);
int main()
{
	Queue q1;
	Queue q2;
	Input(q1, "q1.txt");
	Input(q2, "q2.txt");
	Operations(q1, q2);


}
void Input(Queue& q1, char filename[50])
{
	int number;
	ifstream f;
	f.open(filename);
	while (!f.eof())
	{
		f >> number;
		q1.push(number);
	}
}
void Output(Queue q1)
{
	while (!q1.isEmpty())
	{
		cout << q1.queue_front() << " ";
		q1.pop();
	}
	cout << endl;
}
void Operations(Queue q1, Queue q2)
{
	while (true)
	{
		if (q1.isEmpty())
		{
			break;
		}
		if (q2.isEmpty())
		{
			break;
		}

		int elFromQ1 = q1.queue_front();
		q1.pop();
		int elFromQ2 = q2.queue_front();
		q2.pop();
		int sum = elFromQ1 + elFromQ2;

		if (elFromQ1 > elFromQ2)
		{
			q1.push(sum);
		}
		else
		{
			q2.push(sum);

		}

	}
	if (!q1.isEmpty())
	{
		Output(q1);
	}
	else
	{
		Output(q2);
	}

}
