import java.util.*;

public class ChineseRemainderTheorem{
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    int[] num = new int[n];
    int[] rem = new int[n];

    int p = 1;
    for (int i=0;i<n;i++){
      num[i] = sc.nextInt();
      p*=num[i];
    }

    for (int i=0;i<n;i++){
      rem[i] = sc.nextInt();
    }

    int x = 0;
    for (int i=0;i<n;i++){
      int m1 = p/num[i];
      int m2 = find(m1,num[i]);
      x+=rem[i]*m1*m2;
    }
    x = x%p;

    System.out.println("CRT is "+x);
  }
  private static int find(int m1, int a){
    int i=1;
    while (true){
      if ((m1*i)%a==1) {
        return i;
      }
      i++;
    }
  }
}
