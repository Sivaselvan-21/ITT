
//construct array
import java.util.*;
class Main {
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        ArrayList<Integer> list=new ArrayList<>();
        ArrayList<Integer> pairWise=new ArrayList<>();
        for(int i=0;i<n;i++) 
        {
            for(int j=1;j<=2*n;j++)
            {
               if(list.size()==n){break ;}
               if(!pairWise.contains(j-1+j-2) && !list.contains(j))
               {
                   list.add(j);
                   System.out.println(list);
                   break;
               }
            }
            for(int z=0;z<list.size()-1;z++)
               {
                  if(!pairWise.contains(list.get(z)+list.get(z+1))){
                  pairWise.add(list.get(z)+list.get(z+1));
                  System.out.println(pairWise);}
               }
        }
        System.out.println(list);
        System.out.println(pairWise);
    }
}
