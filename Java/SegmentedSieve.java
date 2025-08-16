import java.util.*;

public class SegmentedSieve{
  private static ArrayList<Integer> simpleSieve(int n){
    ArrayList<Integer> primes = new ArrayList<>();
    boolean[] isPrime = new boolean[n+1];

    Arrays.fill(isPrime, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int p=2;p*p<n;p++){
      if (isPrime[p]){
        for (int i=p*p;i<=n;i+=p){
          isPrime[i] = false;
        }
      }
    }

    for (int i=0;i<=n;i++){
      if (isPrime[i]) {
        primes.add(i);
      }
    }

    return primes;
  }

  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int low = sc.nextInt();
    int high = sc.nextInt();
    ArrayList<Integer> primes = simpleSieve((int)Math.sqrt(high));
    for (int num : primes){
      System.out.println(num);
    }
  }
}
