import java.lang.reflect.Array;
import java.util.*;


public class Main {

  static int N;
  static int K;
  static long Q;
  static int A;
  static int B;
  static long C;
  static double min = 9999999;
  static long ans = 0;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int N = scanner.nextInt();


    scanner.nextLine();

    String s = scanner.nextLine();

    boolean flag = false;
    int ans = 0;
    int hen = 0;
    int sha = 0;
    int dot = 0;
    int temp = 0;
    boolean first = true;
    for (int i = 0; i < N; i++) {


      if(s.charAt(i) == '#'){
        first = false;
          if(sha <= dot){


            ans += sha;
            sha = 0;
            dot = 0;
            first = true;


          }else{




          }

        sha++;
      }else{





          dot++;


      }
    }

    if(sha <= dot){
      ans += sha;
      dot = 0;
    }else{


    }





    System.out.println(ans + dot);
  }
}

