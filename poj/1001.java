import java.math.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BigDecimal a;
        int b;
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            a = cin.nextBigDecimal();
            b = cin.nextInt();
            a = a.pow(b);
            String s = a.toPlainString();
            int start = 0;
            while (s.charAt(start) == '0') start++;
            int end = s.length() - 1;
            while (s.charAt(end) == '0') end--;
            if (s.charAt(end)  == '.') end--;
            for (int i = start; i <= end; ++i) {
                System.out.print(s.charAt(i));
            }
            System.out.println();
        }
        cin.close();
    }
}