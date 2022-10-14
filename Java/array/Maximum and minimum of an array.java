public class MinandMax {
   public int max(int [] array) {
      int max = 0;
     
      for(int i=0; i<array.length; i++ ) {
         if(array[i]>max) {
            max = array[i];
         }
      }
      return max;
   }
   public int min(int [] array) {
      int min = array[0];
     
      for(int i=0; i<array.length; i++ ) {
         if(array[i]<min) {
            min = array[i];
         }
      }
      return min;
   }
   public static void main(String args[]) {
      int[] myArray = {20, 45, 78, 65, 89};
      MinandMax m = new MinandMax();
      System.out.println("Maximum array:"+m.max(myArray));
      System.out.println("Minimum array:"+m.min(myArray));
   }
}

// code by Rufus paul
