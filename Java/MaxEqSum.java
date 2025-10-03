import java.util.*;

public class MaxEqSum {
  public static void main (String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] nums = new int[n];
    
    int totalCount = 0;
    for (int i=0;i<n;i++){
      nums[i] = sc.nextInt();
      totalCount+=nums[i];
    }
    int targetSum = totalCount/2;

    int minDiff = Integer.MAX_VALUE;
    
    int currCount = 0;
    for (int i=0;i<n;i++){
      currCount+=nums[i];
      minDiff= Math.min(minDiff,Math.abs(targetSum-currCount));
    }

    System.out.println("Max equilibrium sum is "+(targetSum+minDiff));
  }
}
