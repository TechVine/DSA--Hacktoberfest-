import java.util.*;
public class InsertionSort {
    void sort(int arr[])
    {
        int n = arr.length;
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
 
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
 
        System.out.println();
    }
 
    public static void main(String args[])
    {
        int n;
        
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter Range: ");
        n= sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter elements: ");
        for(int i=0;i<n;i++)
            arr[i]= sc.nextInt();
        InsertionSort ob = new InsertionSort();
        ob.sort(arr);
    }
}
