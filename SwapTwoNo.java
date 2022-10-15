class SwapTwoNo{
    public static void main(String args[]) {
        int a = 10;
        int b = 20;
       int temp;
        System.out.println("Before Swap:" +a+ " , " +b);
       
        temp = a;
        a = b;
        b=temp;

        System.out.println("After Swap" +a+ ", " +b);
    }
}