import java.util.Scanner;

class BinSearch {
    static int binarySearch(int[] arr, int low, int high, int key) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == key) return mid;
            if (arr[mid] < key) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the lenth of the array: ");
        int arrLen = sc.nextInt();

        int[] arr = new int[arrLen];

        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < arrLen; i++) 
            arr[i] = sc.nextInt();
        
        System.out.print("Enter the key: ");
        int key = sc.nextInt();
        
        int low = 0,
            high = arrLen - 1;
        
        if (binarySearch(arr, low, high, key) == -1)
            System.out.println("Element not found!");
        else
            System.out.println("The key " + key + " is at index " + binarySearch(arr, low, high, key));
        sc.close();
    }
}
