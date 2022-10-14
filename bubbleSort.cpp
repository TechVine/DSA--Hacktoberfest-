#include <iostream>
using namespace std;

const int N = 1e5+10;
int arr[N];

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;   
}

void display(int *arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl ;
}

void bubbleSort(int *arr, int size) {
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++) // size-i-1 bcz last element is placed at its correct position
        {
            display(arr, size);
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if (!flag) return;
    }
}

int main()
{
    int n;
    cout << "Enter the size of an  array: "; cin >> n;
    cout << "Enter " << n << " elements " << endl ;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    bubbleSort(arr, n);
    display(arr, n);
    return 0;
}