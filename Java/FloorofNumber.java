package LeetCode.Binary_Search;
import java.util.Scanner;
public class FloorofNumber {

    public static void main(String[] args) {

        int[] arr = {2,3,5,9,14,16,18};
        System.out.println("Enter the element which you want to find");
        Scanner sc = new Scanner(System.in);
        int target =sc.nextInt();
    int ans=binarySearch(arr,target);
    System.out.println(ans);


        
    }


    static int binarySearch(int[] arr, int target){
      int start=0;
      int end=arr.length-1;

      while(start<=end){

        int mid = start+ (end-start)/2;

        if(target<arr[mid]){

            end= mid-1;
        }

        else if(target>arr[mid]){

            start= mid+1;
      }

      else{

        return mid;
      }
      
    }
    return end;
    
}
}
