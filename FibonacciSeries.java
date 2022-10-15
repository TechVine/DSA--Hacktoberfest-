public class FibonacciSeries {
    public static void main(String[] args){
        int n1=0;
        int n2=1;
        int sum;
        int count = 10;

        System.out.print(n1+" ,"+n2);

        for(int i=2; i<count; i++){
            sum=n1+n2;
            System.out.print(", "+sum);
            n1=n2;
            n2=sum;
        }
    }
}
