import java.util.*;

class Signal{
    public int idx;
    public int height;
    public Signal(int a,int b){
        idx = a;
        height = b;
    }
}

class Solution {
    public int[] solution(int[] heights) {
        int[] answer = new int[heights.length];
        Stack<Signal> st = new Stack<Signal>();
        for(int i = heights.length-1; i>=0; i--){
            while(!st.isEmpty() && st.peek().height < heights[i]){
                answer[st.peek().idx] = i + 1;
                st.pop();
            }
            st.push(new Signal(i,heights[i]));
        }
        return answer;
    }
}
