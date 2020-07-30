//Main idea: 큐 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
 
public class Solution {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
     
    public static void main(String[] args) throws IOException {
        for(int i = 1; i <=10 ; i++) {
            in.readLine();
            sb.append("#" + i + " ");
            run();
        }
        System.out.println(sb);
    }
     
    static void run() throws IOException {
        st = new StringTokenizer(in.readLine(), " ");
        Queue<Integer> que = new LinkedList<Integer>();
         
        for(int i = 0; i < 8; i++) 
            que.offer(Integer.parseInt(st.nextToken()));
        int cnt = 1;
        while(true) {
            int num = que.poll();
            num = (num >= cnt)? num-cnt++ : 0;
            que.offer(num);
            if(num == 0) break;
            if(cnt == 6) cnt = 1;
        }
        for(int a: que)
            sb.append(a + " ");
        sb.append("\n");
    }
}
