import java.util.Scanner;

public class palidrom {
    public static void main(String[] args) {
        int z;
        int rev = 0;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Length: ");
        int c = sc.nextInt();
        z = c;
        while (c > 0) {
            rev = (rev * 10) + c % 10;
            c = c / 10;
        }
        if (rev == z) {
            System.out.print("Number is palindrome");
        } else {
            System.out.print("Number is not palindrome");
        }
        sc.close();
    }
}