import java.util.*;

public class LongestOnes {
  public static void main (String[] args){
    Scanner sc = new Scanner(System.in);

    System.out.print("Enter the binary string:");
    String str = sc.nextLine();
    char[] charArr = str.toCharArray();
    System.out.print("Enter k value:");
    int k = sc.nextInt();

    int left = 0;
    int right = 0;
    int zeroes =0;
    int maxLenSoFar = 0;

    while (right<charArr.length){
      if (charArr[right]=='0'){
        zeroes++;
      }
      
      while (zeroes>k){
        if (charArr[left]=='0'){
          zeroes--;
        }
        left++;
      }

      maxLenSoFar = Math.max(maxLenSoFar, right-left+1);
      right++;
    }

    System.out.println("Longest subarray of 1s that can be formed is of length: "+maxLenSoFar);
  }
}
