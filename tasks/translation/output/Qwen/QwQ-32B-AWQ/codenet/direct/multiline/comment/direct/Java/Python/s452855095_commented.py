//package Contest081;

import java.io.PrintWriter;
import java.util.Scanner;

public class s452855095_commented {
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
            int n = sc.nextInt();
            int arr []=new int [n];
            for(int i=0;i<n;i++)
                arr[i]=sc.nextInt();
            int cnt =0;
            boolean flag = true;
            while(true)
            {
                for(int i=0;i<n;i++)
                {
                    if(arr[i]%2!=0)
                    {
                        flag = false;
                        break;
                    }
                    else
                        arr[i] = arr[i]/2;
                }
                if(flag==true)
                    cnt++;
                else
                    break;
            }
                out.println(cnt);
        out.flush();
    }
}

n = int(input())
arr = list(map(int, input().split()))
cnt = 0
while True:
    flag = True
    for i in range(n):
        num = arr[i]
        if num % 2 != 0:
            flag = False
            break
        else:
            arr[i] = num // 2
    if not flag:
        break
    else:
        cnt += 1
print(cnt)
# End of Code
