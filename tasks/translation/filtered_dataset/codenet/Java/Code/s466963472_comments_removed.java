

import java.util.*;
public class Main {
	
	static Scanner sc = new Scanner(System.in);
	static int d;
	
	static boolean read() {
		if(!sc.hasNextInt()) return false;
		d = sc.nextInt();
		return true;
	}
	
	static int solve() {
		int ans,n;

		ans = 0;
		for(int i = 1; i * d < 600; i++) {
			int x = i * d;
			int y = x * x;
			ans += y * d;
		}
		return ans;
	}
	
	
	public static void main(String[] args) {
		while(read()) {
			System.out.println(solve());
		}
	}

}