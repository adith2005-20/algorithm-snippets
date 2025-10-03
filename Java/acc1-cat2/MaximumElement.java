import java.util.*;
public class MaximumElement {
  public static void main (String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int[] arr = new int[n];
    for (int i=0;i<n;i++){
      arr[i] = sc.nextInt();
    }

    int candidate = -1;
    int votes = 0;
    for (int i=0;i<n;i++){
      if (votes==0){
        candidate = arr[i];
        votes=1;
      }
      else if (arr[i]==candidate){
        votes++;
      }
      else{
        votes--;
      }
    }
    
    int count = 0;
    for (int i: arr){
      if (i==candidate){
        count++;
      }
    }

    if (count> (n/2)){
      System.out.println(candidate+" is the Majority Element in the array with count "+count);
    }
    else{
      System.out.println("No majority element found in given array."+count);
    }
  }
}
