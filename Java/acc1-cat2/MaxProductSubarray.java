import java.util.*;

public class MaxProductSubarray {
  public static void main (String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] nums = new int[n];

    for (int i=0;i<n;i++){
      nums[i] = sc.nextInt();
    }
    
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];
    int minEndingHere = nums[0];

    for (int i=1;i<n;i++){
      int temp = maxEndingHere;
      maxEndingHere = Math.max(nums[i], Math.max(nums[i]*maxEndingHere,nums[i]*minEndingHere));
      minEndingHere = Math.min(nums[i], Math.min(nums[i]*temp, nums[i]*minEndingHere));
      maxSoFar = Math.max(maxSoFar, maxEndingHere);
    }

    System.out.println("Maximum Product subarray has a product = "+maxSoFar);
  }
}
