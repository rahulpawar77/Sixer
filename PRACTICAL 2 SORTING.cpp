#include <iostream>
using namespace std;

void selectionSort(float a[],int n)
{
	int comparisons = 0;
	for(int i = 0; i < n - 1; i++)
	{
		int min = i;
		for(int j = i + 1; j < n; j++)
		{
			comparisons++;
			
			if (a[j] < a[min])
			min = j;
		}
		float temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	cout << "\nSorted Percentages:\n";
	for(int i = 0; i < n; i++)
	cout << a[i] << " ";
	cout << "\nTop Five Scores:";
	for(int i = n - 1; i >= n - 5 && i >= 0; i--)
	cout << a[i] << " ";
	cout << "\nTotal Comparisons = " << comparisons << endl;
}

void bubbleSort(float a[], int n)
{
	int comparisons = 0;
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			comparisons++;
			if(a[j] > a[j + 1])
			{
				float temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	cout << "\nSorted Percentages:\n";
	for(int i = 0; i < n; i++)
	cout << a[i] << " ";
	cout << "\nTop Five Scores: ";
	for(int i = n - 1; i >= n - 5 && i >= 0; i--)
	cout << a[i] << " ";
	cout << "\nTotal Comparisons = " << comparisons << endl;
}

int main()
{
	cout<<"========= STUDENT NAME : SHRAVAN SALVE ==========" <<endl;
    cout<<"=========     ROLL NO. : 231    ==========" <<endl;
	int n, choice;
	cout << "Enter number of students:";
	cin >> n;
	float per[n], temp[n];
	
	cout << "Enter Percentages:\n";
	
	for (int i = 0; i < n; i++)
	cin >> per[i];
	do
	{
		for(int i = 0; i < n; i++)
		temp[i]= per[i];
		
		cout << "\n========== MENU ==========";
		cout << "\n1. Selection Sort"; 
		cout << "\n2. Bubble Sort";
		cout << "\n3. Exit";
		cout << "\nEnter Choice:";
		cin >> choice;
		
		switch(choice)
		{
			case 1:
				cout << "\n--- Selection Sorting ---\n";
				selectionSort(temp, n);
				break;
			case 2:
				cout << "\n---Bubble Sorting ---\n";
				bubbleSort(temp, n);
				break;
			case 3:
				cout << "\nProgram Terminated...";
				break;
			default:
				cout << "\nInvalid Choice!";
				cout << "\nPlease enter correct choice!";
		}
	}while(choice != 3);
	return 0;
}



