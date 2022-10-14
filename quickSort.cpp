/* **************************************************************
 * TIME COMPLEXITY: O(N^2)
 * AVERAGE : O(NlogN)
 * BEST : O(NlogN)
 * **************************************************************/
#include <iostream>
using namespace std;
const int N = 1e5+10;
int arr[N];

void swap(int *a, int *b)
{
    int temp = *a; // auxiliary space
    *a = *b;
    *b = temp;
}

void display(int *arr, int startIndex, int endIndex)
{
    for (int i = startIndex; i < endIndex; i++)
        cout << arr[i] << " ";
    cout << '\n';
}

int partition(int *arr, int low, int high)
{
    int i = low + 1;  
    int j = high;
    int pivot = arr[low];

    do {
        while (arr[i] <= pivot) // for greater element 
            i++;
        while (arr[j] > pivot) // for smaller element
            j--;
        if (i < j) swap(&arr[i], &arr[j]);

    } while (i < j);

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int *arr, int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main(void)
{
    // int arr[] = {1, 8, 3, 9, 4, 5, 7};
    int size;
    cout << "Enter the size: "; cin >> size;
    cout << "Enter the " << size << " elements" << endl ;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    
    cout << "\n Before Sort\n";
    display(arr, 0, size);
    cout << "\n QuickSort: ";
    quickSort(arr, 0, size - 1);
    display(arr, 0, size);

    return 0;
}