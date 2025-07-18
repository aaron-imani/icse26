import java.util.*;
public class Main {


	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), Q = sc.nextInt();
		String s = sc.next();
		int pre[] = new int[N+1];
		for(int i = 1; i<N; i++) {
			if(s.charAt(i-1) == 'A' && s.charAt(i) =='C') {
				pre[i] = 1;

			}
		}


		for(int i = 1; i<N; i++) {
			pre[i] += pre[i-1];
		}


		while(Q-- > 0) {
			int l = sc.nextInt(), r = sc.nextInt();
			r--;
			System.out.println(pre[r] - pre[l-1]);
		}
	}
}
