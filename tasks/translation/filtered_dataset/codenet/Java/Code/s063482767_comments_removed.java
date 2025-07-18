import java.util.*;

public class Main {

    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for(int i = 0; i < n; i++) {
            queue.add(sc.nextInt());
        }
        int sum = 0;
        for(int i = 0; i < n - 1; i++) {
            sum += queue.poll();
        }



        System.out.println(queue.poll() < sum ? "Yes" : "No");
    }
}
