
//Bubble Sort Technique Using Java
public class BubbleSort {

	public static void sortArray(int arr[]) {
		
		System.out.print("Unsorted Array : ");
		for(int i = 0; i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		
		System.out.println();
		
		for(int i=0; i<arr.length-1;i++) {
			for(int j=0;j<arr.length-i-1;j++) {
				
				if(arr[j]>arr[j+1]) {
					
				//swapping by comparing adjacent elements
				int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				}
			}
		}
    
    //Priting the Sorted Array
		System.out.print("Sorted Array : ");
		for(int i = 0; i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
		}
	public static void main(String[] args) {
		
    // Array Creation
		int arr[] = {5,1,6,7,9,2};

    // Passing the array to the sortArray Method which will Sort the Array.
			sortArray(arr);
	}
}
