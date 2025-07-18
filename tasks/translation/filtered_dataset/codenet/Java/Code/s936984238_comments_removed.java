import java.util.*;
public class Main {
	static Scanner sc = new Scanner(System.in);

	static int[] score;
	static int number;
	public static void main(String[] args) {


		while(read()){
			slove();
		}
	}
	static boolean read(){
		number = sc.nextInt();
		if(number == 0)
			return false;
		
		score = new int[number];
		for(int i = 0; i < number; i++){
			score[i] = sc.nextInt();
		}
		return true;
	}
	static void slove(){
		java.util.Arrays.sort(score);
		int sum = 0;
		for(int i = 1; i < number-1; i++){
			sum = sum + score[i];
		}
		System.out.println(sum/(number-2));
	}
}