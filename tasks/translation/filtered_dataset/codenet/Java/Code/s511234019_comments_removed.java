

import java.util.*;
import java.lang.*;
import java.io.*;


public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner in =new Scanner(System.in);
		int a,b;
		a=in.nextInt();
		b=in.nextInt();
		if(a%2==0 || b%2==0 )
			System.out.println("No");
		else
			System.out.println("Yes");
	}
}