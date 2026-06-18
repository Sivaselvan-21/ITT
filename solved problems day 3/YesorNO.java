
//Yes or No
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        String s = sc.next();
        char[] arr = s.toCharArray();
        for (int i = 0; i <= n - k - 1; i++) {
            if (arr[i] == '1') {
                arr[i] = '0';
                if (arr[i + k] == '1') {
                    arr[i + k] = '0';
                } else {
                    arr[i + k] = '1';
                }
            }
        }
        boolean possible = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] == '1') {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        
        sc.close();
    }
}
