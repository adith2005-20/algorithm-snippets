import java.util.*;

public class LexicoFirstString {
  public static void main (String[] args){
    Scanner sc = new Scanner(System.in);
    String str = sc.nextLine();

    int[] map = new int[26];

    Arrays.fill(map, 0);

    char[] charArr = str.toCharArray();

    for (char c: charArr){
      map[c-'a']++;
    }

    int oddCount = 0;

    for (int i=0;i<26;i++){
      if (map[i]%2==1){
        oddCount++;
      }
      if (oddCount>1){
        System.out.println(-1);
        return;
      }
    }

    char[] result = new char[charArr.length];
    int left=0;
    int right = charArr.length-1;

    for (int i=0;i<26;i++){
      int count = map[i];
      char ch = (char)('a'+i);
      while (count>=2) {
        result[left++]=ch;
        result[right--]=ch;
        count-=2;
      }
      if (count==1){
        result[charArr.length/2]=ch;
      }
    }
    
    System.out.println(new String(result));
  }
}
