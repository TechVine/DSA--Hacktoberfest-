public class SwapNoUsingArthOperator {
    public static void main(String[] args) {
        int a=10;
        int b=20;

        System.out.println("Before Swap" +a+ "," +b);

        a = a^b; //30
        b = a^b;
        a = a^b;

        System.out.println("After Swap" +a+ "," +b);


    }
}
