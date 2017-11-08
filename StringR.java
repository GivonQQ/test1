/**
 * Name:
 * ID:104213055
 */
import java.util.Scanner;
public class StringReverse {
    public static void main (String[] argv){
        Scanner input = new Scanner(System.in);
        String word = input.next();
        int n = input.nextInt();
        for (int i = 0; i < word.length() - word.length() % n; i+=n){
            int B = i;
            for (int j = B + n - 1; j >= B; j--) {
                System.out.print(word.charAt(j));
            }
        }
        for (int i = word.length() - 1; i >= word.length() - word.length() % n; i--)
            System.out.print(word.charAt(i));
        System.out.println();
    }
}
