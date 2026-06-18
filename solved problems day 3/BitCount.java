
//bitcount
import java.util.*;
class Main
{
    public static void main(String args[]){
      Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      String binary = Integer.toBinaryString(n);
      int c=Integer.bitCount(n);
      if(c==0){
         System.out.println("Invalid input");
      }
    }
}
