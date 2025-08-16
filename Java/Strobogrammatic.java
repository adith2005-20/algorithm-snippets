import java.util.*;

public class Strobogrammatic{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();

    String foo = String.valueOf(n);
    int len = foo.length();
    for (int i=0;i<len;i++){
      if (foo.charAt(i)=='6' && foo.charAt(len-i-1)=='9'){
        continue;
      }
      else if (foo.charAt(i)=='8' && foo.charAt(len-i-1)=='8'){
        continue;
      }
      else if (foo.charAt(i)=='9' && foo.charAt(len-i-1)=='6'){
        continue;
      }
      else if (foo.charAt(i)=='1' && foo.charAt(len-i-1)=='1'){
        continue;
      }
      else{
        System.out.println("This number IS NOT a Strobogrammatic number");
        return;
      }
    }
    System.out.println("This number IS a Strobogrammatic number");
  }
}
