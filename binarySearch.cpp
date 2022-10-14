#include <iostream>
using namespace std;

const int N = 1e5+10;
int arr[N];

// recursive B-Search
int binarySearch(int *arr, int left, int right, int value) {
    if (right >= left) {
        int mid = left + (right - left) / 2; // -> (right + left) / 2

        // check th mid
        if (value == arr[mid]) return mid;

        // left side
        if (value < arr[mid]) return binarySearch(arr, left, mid - 1, value);
        
        // right side
        return binarySearch(arr, mid + 1, right, value);
    }
    return -1;
}

int main()
{
    int n;
    cout << "Array must be in ascending order" << endl ;
    cout << "Enter the size of an array: " ; cin >> n ;
    cout << "Enter the " << n << " elements" << endl ;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int value;
    cout << "Enter the element to be searched: "; cin >> value;
    cout << "index: " << binarySearch(arr, 0, n-1, value);

    return 0;
}