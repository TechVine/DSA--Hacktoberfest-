import java.util.Arrays;
// non-comparison based algorithm
// Time Complexity : O(nd) where n = size of the array & d = number of digits in the largest number
// It requires extra space
public class Radix_sort {
    public static void radixSort(int[] a,int d){
        for(int x=1;x<=d;x++){
            for(int i=1;i<a.length;i++){
                int key = a[i];
                int j=i-1;
                while(j>=0 && (int)(a[j]/Math.pow(10,x-1)%10)>(int)(key/Math.pow(10,x-1)%10)){
                    a[j+1]=a[j];
                    j--;
                }
                a[j+1] = key;
            }
            System.out.println(x + " time sort" + ":");
            System.out.println(Arrays.toString(a));
        }
    }

    public static void main(String[] args) {
        int[] a = {329,457,657,839,436,720,355};
        radixSort(a,3);
    }
}
