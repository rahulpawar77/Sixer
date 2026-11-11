#include <iostream>
#include <algorithm>

using namespace std;

void linearSearch(int arr[], int n, int key)
{
     int comparisons=0;
     
     for (int i = 0; i < n; i++)
     {
         comparisons++;
         if (arr[i] == key)
         {
                    cout << "\nStudent attended the session.";
                    cout << "\nPosition : " << i;
                    cout << "\nTotal Comparisons = " << comparisons << endl;
                    return;
         }
     }
     
     cout << "\nStudent did not attend the session.";
     cout << "\nTotal Comparisons = " << comparisons << endl;
}

void binarySearch(int arr[], int n, int key)
{
     sort(arr, arr + n);
     
     int low = 0;
     int high = n-1;
     int comparisons = 0;
     
     while (low<= high)
     {
           comparisons++;
           
           int mid = (low + high) / 2;
           
           if (arr[mid] == key)
           {
                        cout << "\nStudent attended the session";
                        cout << "\nPosition in sorted array : " << mid + 1;
                        cout << "\nTotal comparisons = " << comparisons << endl;
                        return;
           }
           else if (key < arr[mid])
           {
                high = mid -1;
           }
           else
           {
               low = mid + 1;
           }
     }
     
     cout << "\nStudent did not attended the session";
     cout << "\nTotal comparisons = " << comparisons << endl;
}

int main()
{
    cout<<"========= STUDENT NAME : SHRAVAN SALVE ==========" <<endl;
    cout<<"=========     ROLL NO. : 231    ==========" <<endl;
    int n, choice, key;
    
    cout << "Enter number of students : ";
    cin >> n;
    
    int arr[n];
    
    cout << "\nEnter roll numbers:\n";
    
    for (int i = 0; i<n; i++)
    cin >> arr[i];
    
    do
    {
        cout << "\n======== MENU ========\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        
        switch (choice)
        {
               case 1:
                    cout << "Enter roll number to search : ";
                    cin >> key;
                    linearSearch(arr, n, key);
                    break;
                    
               case 2:
                    cout << "Enter roll number to search : ";
                    cin >> key;
                    binarySearch(arr, n, key);
                    break;
                    
                case 3:
                	cout << "\nProgram Terminated.";
                	break;
                	
                default:
                	cout << "\nInvalid Choice!";
                	
        }
    }
    while (choice != 3);
    
    return 0;
}
