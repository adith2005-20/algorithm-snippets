import java.util.*;

public class BinaryPalindrome{
  public static void main(String args[]){
    Scanner sc =  new Scanner(System.in);
    String inputstr = sc.next();
    int n = inputstr.size();
    for (int i=0;i<n/2;i++){
      char start = inputstr.charAt(i);
      char end = inputstr.charAt(n-1-i);
      if (start==end){
        continue;
      }
      else {
        System.out.println("Not a binary palindrome");
        return;
      }
    }
    Systm.out.println("Binary Palindrome");
  }
}
