#include <bits/stdc++.h>
using namespace std;

// in increasing order when heapSort() is called.

class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        // Your Code Here
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest])
        {
            largest = l;
        }
        if (r < n && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

public:
    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // Your Code Here
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

public:
    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // code here
        buildHeap(arr, n);
        int size = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

int main()
{
    int arr[5] = {1, 5, 78, 32, 7};
    int n = 5;
    Solution s;
    s.heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
