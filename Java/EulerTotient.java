import java.util.*;
import java.math.BigInteger;

public class EulerTotient{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    BigInteger one = BigInteger.ONE;

    int n = sc.nextInt();
    int ans = 0;
    for (int i=0;i<=n;i++){
      BigInteger n1 = BigInteger.valueOf(i);
      BigInteger n2 = BigInteger.valueOf(n);
      if (n1.gcd(n2).equals(one)){
        ans++;
      }
    }

    System.out.println("Euler's Totient value for "+n+" is "+ans);
  }
}
