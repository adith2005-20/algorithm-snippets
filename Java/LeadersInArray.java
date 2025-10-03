import java.util.*;

public class LeadersInArray {
  public static void main (String[] args){
    Scanner sc =  new Scanner(System.in);
    ArrayList<Integer> leaders = new ArrayList<>();
    int n = sc.nextInt();
    int[] nums = new int[n];
    for (int i=0;i<n;i++){
      nums[i]= sc.nextInt();
    }
    
    int currentMax = nums[n-1];
    for (int i=n-1;i>=0;i--){
      if (nums[i]>=currentMax){
        leaders.add(nums[i]);
        currentMax = Math.max(nums[i], currentMax);
      }
    }

    
    System.out.println("Leaders of the array are:");
    for (int i=0;i<leaders.size();i++){
      System.out.println(leaders.get(i));
    }
  }
}
