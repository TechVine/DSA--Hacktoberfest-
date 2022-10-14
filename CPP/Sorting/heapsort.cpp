// Heap sort in C++

//Yash sarnaik 
#include <iostream>
  using namespace std;
  
  void heapify(int arr[], int n, int i) { //heapify function
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
      if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
  }
  
  void heapSort(int arr[], int n) {  //heap sort function
    
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
  
      
      heapify(arr, i, 0);
    }
  }
  
  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
  }
  
  int main() {
    int n;
    cout<<"enter the no. of elements you want in your array: ";
	cin>>n;
	int arr[n];
    for(int i=0; i<n;i++)
    	cin>>arr[i];
    n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
  
    cout << "Sorted array is \n";
    printArray(arr, n);
  }
