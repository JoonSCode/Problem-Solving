//Main idea: 스택 연습
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
 
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static char[] openArr = {'{','[','(','<'};
    private static char[] closeArr = {'}',']',')','>'};
     
    public static void main(String[] args) throws IOException {
        for(int i = 0; i < 10; i++) 
            System.out.println("#"+(i+1) + " " + run());
    }
     
    static int run() throws IOException {
        int size = Integer.parseInt(br.readLine());
        char[] arr = br.readLine().toCharArray();
        Stack<Integer> st = new Stack<Integer>();
        int cnt = 0;
        for(char a : arr) {
            int idx = isOpen(a);
            if(idx != -1) {
                cnt++;
                st.add(idx);
            }
            else {
                if(cnt-- < 0 || st.pop() != idxOfCloseArr(a))
                    return 0;
            }
        }
        return (st.isEmpty())? 1 : 0;
    }
    private static int isOpen(char a) {
        for(int i = 0; i < 4; i++) {
            if(openArr[i] == a)
                return i;
        }
        return -1;
    }
     
    private static int idxOfCloseArr(char a) {
        for(int i = 0; i < 4; i++) {
            if(closeArr[i] == a)
                return i;
        }
        return -1;
    }
}
