
public class CheckNoPrimeOrNot {
   public static void main(String[] args) {
       int a = 1;
     //  int temp = 0;

       for(int i=2; i<=a/2; i++){
          if(a%i==0){
                System.out.println("Number Is Prime");
          }else{
              System.out.println("Number Is Not Prime");
          }
       }
   }   
}
