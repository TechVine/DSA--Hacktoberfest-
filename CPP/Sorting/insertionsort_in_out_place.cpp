#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// function to print array
void print(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
}
// simple insertion sorting - inplac
void insertion_sort(int arr[], int n)
{
   for (int i = 0; i < n; i++) // for passes
   {
      // for comparisons
      int j = i;
      while (j >= 0 && arr[j] > arr[j + 1])
      {
         // swap operation
         int temp = arr[j];
         arr[j] = arr[j + 1];
         arr[j + 1] = temp;
         j--;
      }
   }
   print(arr, n);
}
void insertion_sort_op(int arr[], int s, int l)
{
   // s - start
   // l - end
   if (s == l)
   {
      return;
   }

   int j = s + 1;
   int temp = arr[j];
   while (s >= 0)
   {
      if (arr[s] > temp)
      {
         arr[s + 1] = arr[s];
         s--;
      }
      if (s == -1)
      {
         arr[0] = temp;
         break;
      }
      if (arr[s] <= temp)
      {
         arr[s + 1] = temp;
         break;
      }
      insertion_sort_op(arr, s + 1, l);
   }
}
int main()
{
   cout << "Input the size of the array"
        << " ";
   int n;
   cin >> n;
   int arr[n];
   cout << "Input the elements of the array"
        << " ";
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << "Array before sorting"
        << " ";
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   cout << "Array after sorting - inplace"
        << " ";
   insertion_sort(arr, n);
   cout << endl;
   cout << "Array after sorting - outplace"
        << " ";
   insertion_sort_op(arr, 0, n - 1);
   print(arr, n);

   return 0;
}
