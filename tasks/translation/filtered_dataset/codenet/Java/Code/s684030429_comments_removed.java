

import java.io.*; 
import java.util.*;
import java.math.*;



public class Main 
{ 
    Scanner sc;
    int max = 0,cur = 0;


    void solve(){
        int a = ni();
        int b = ni();

        System.out.println(Math.max(0, a-2*b));
    }









    Main(){
        try{  
            sc = new Scanner(System.in);
        }catch(Exception e){
            System.out.println(e);
        }
    }




    public static void main(String[] args) 
    { 
    	new Main().solve();
    }






    int ni()
    {
        int a = sc.nextInt();
        return a;
    }


    long nl()
    {
        return sc.nextLong();
    }


    float nf(){
        float a = sc.nextFloat();
        return a;
    }


    double nd(){
        double a = sc.nextDouble();
        return a;
    }


    String ns(){
        return sc.nextLine();
    }


    StringTokenizer nst(String s){
        return new StringTokenizer(s);
    }


    void ia(int a[]){
        for(int i = 0;i < a.length;i++)
            a[i] = sc.nextInt();
    }


    void la(long a[]){
        for(int i = 0;i < a.length;i++)
            a[i] = sc.nextLong();
    }


    void fa(float a[]){
        for(int i = 0;i < a.length;i++)
            a[i] = sc.nextFloat();
    }


    void da(double a[]){
        for(int i = 0;i < a.length;i++)
            a[i] = sc.nextDouble();
    }


    void sa(String a[], boolean empty){
        if(empty)
        {
            for(int i = 0;i < a.length;i++)
            {
                a[i] = "";
            }
        }
        else
        {
            for(int i = 0;i < a.length;i++)
            {
                a[i] = ns();
            }
        }
    }


    void ida(int a[][], int n, int m)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                a[i][j] = ni();
            }
        }
    }


    void lda(long a[][], int n, int m)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                a[i][j] = nl();
            }
        }
    }


    void dda(double a[][], int n, int m)
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                a[i][j] = nd();
            }
        }
    }


    int stoi(String s){
        return Integer.parseInt(s);
    }


    double stod(String s){
        return Double.parseDouble(s);
    }


    long lmin(long a[])
    {
        long min = Long.MAX_VALUE;
        for(int i = 0;i < a.length;i++)
        {
            if(min > a[i])
                min = a[i];
        }
        return min;
    }


    int imin(int a[])
    {
        int min = Integer.MAX_VALUE;
        for(int i = 0;i < a.length;i++)
        {
            if(min > a[i])
                min = a[i];
        }
        return min;
    }


    long lmax(long a[])
    {
        long max = Long.MIN_VALUE;
        for(int i = 0;i < a.length;i++)
        {
            if(max < a[i])
                max = a[i];
        }
        return max;
    }


    int imax(int a[])
    {
        int max = Integer.MIN_VALUE;
        for(int i = 0;i < a.length;i++)
        {
            if(max < a[i])
                max = a[i];
        }
        return max;
    }


    boolean ibs(int a[], int toFind)
    {
        Arrays.sort(a);
        int min = 0;
        int max = a.length-1;
        boolean found = false;

        while(min <= max && !found)
        {
            int mid = min + (max-min)/2;
            if(a[mid] == toFind)
            {
               found = true;
            }
            else if(toFind > a[mid])
            {
                min = mid+1;
            }
            else
            {
                max = mid-1;
            }

        }
        return found;
    }


    boolean lbs(long a[], long toFind)
    {
        Arrays.sort(a);
        int min = 0;
        int max = a.length-1;
        boolean found = false;

        while(min <= max && !found)
        {
            int mid = min + (max-min)/2;
            if(a[mid] == toFind)
            {
               found = true;
            }
            else if(toFind > a[mid])
            {
                min = mid+1;
            }
            else
            {
                max = mid-1;
            }

        }
        return found;
    }

    int stb(String s)
    {
        int sum = 0;
        int k = 0;
        for(int i = s.length()-1;i >= 0;i--)
        {
            sum += stoi(s.charAt(i)+"") * Math.pow(2, k++);
        }
        return sum;
    }

}