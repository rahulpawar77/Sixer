#include <iostream>
using namespace std;
int queue[100];
int front = 0;
int rear = -1;
int count = 0;
int m;

void addorder()
{
	if( count == m){
		cout << " queue is full\n";
		return;
	}
	
int order;
 cout << " Enter order number : ";
 cin >> order;

 rear++;
 queue[rear] = order;
 count++;
 cout << " Order added successfull.\n";	
}

void deleteorder()
{
	if(count == 0)
	{
		cout << " Queue is empty!\n";
		return;
	}
	cout << "Delete order:" << queue[front] << endl;
	front++;
	count--;
}
void display()
{
	if(count == 0)
	{
		cout << "Queue is empty!\n";
		return;
	}
	cout << "orders in Queue: ";
	for (int i = front; i <= rear; i++)
	cout << queue[i] << " ";
	cout << endl;
}

int main()
{
	cout << "======= STUDENT NAME : OM SONAWANE =======\n";
	cout << "=======      ROLL NO : 244      =======\n";
	int choice;
	cout << " Enter Maximum Queue Size : ";
	cin >> m;
	do
	{
		cout << "\n === ORDER QUEUE ===\n";
		cout << "1. Add Order:\n";
		cout << "2. Delete Order:\n";
		cout << "3. Display Orders:\n";
		cout << "4. Exit\n";
		cout << " Enter Choice:";
		cin >> choice;
		if(choice == 1)
		{
			cout << " How many orders do you want to add ?";
			cin >> m;
			for(int i = 0; i < m; i++)
			addorder();
		}
		else if(choice == 2)
		deleteorder();
		else if(choice == 3)
		display();
		else if(choice == 4)
		cout << "Program Ended.\n";
		else
		cout << "Invalid choice!\n";
	}
	while(choice !=4 );
	return 0;
}

