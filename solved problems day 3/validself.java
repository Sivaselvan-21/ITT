//valid self
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            if (isValidShelf(a)) {
                System.out.println("YES");
                continue;
            }
            boolean found = false; 
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                    
                    if (isValidShelf(a)) {
                        found = true;
                        temp = a[i];
                        a[i] = a[j];
                        a[j] = temp;
                        break;
                    }
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
                if (found) break;
            }
            if (found) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        sc.close();
    }
    private static boolean isValidShelf(int[] a) {
        int n = a.length;
        boolean[] seen = new boolean[100005]; 
        int last = -1;
        
        for (int i = 0; i < n; i++) {
            if (a[i] != last) {
                if (seen[a[i]]) {
                    return false;
                }
                seen[a[i]] = true;
                last = a[i];
            }
        }
        return true;
    }
}

