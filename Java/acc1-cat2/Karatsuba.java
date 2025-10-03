import java.util.*;

public class Karatsuba{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int num1 = sc.nextInt();
    int num2 = sc.nextInt();

    System.out.println("The  answer is:"+karatsubaMultiplication(num1,num2));
  }

  public static int karatsubaMultiplication(int x,int y){
    if (x<10 || y<10) return x*y;
    int n = Math.max(Integer.toString(x).length(),Integer.toString(y).length());
    int m = n/2;
    int high1 = x/(int)Math.pow(10,m);
    int low1 = x%(int)Math.pow(10,m);
    int high2 = y/(int)Math.pow(10,m);
    int low2 = y%(int)Math.pow(10,m);

    int z0 = karatsubaMultiplication(low1,low2);
    int z1 = karatsubaMultiplication((low1+high1),(low2+high2));
    int z2 = karatsubaMultiplication(high1,high2);

    return (int)(z2*Math.pow(10,2*m)+(z1-z2-z0)*Math.pow(10,m)+z0);
  }
}
