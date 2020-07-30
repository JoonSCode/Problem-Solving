//Main idea: 스택 2개 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();
	
	private static int numOfTower;
	private static int[] answer;
	private static Stack<int[]> stack;
	
	public static void main(String[] args) throws IOException {
			laser();
		System.out.println(sb);
	}
	
	private static void laser() throws NumberFormatException, IOException {
		numOfTower = Integer.parseInt(in.readLine());
		init();
		st = new StringTokenizer(in.readLine()," ");
		for(int i = 0; i < numOfTower; i++) 
			stack.add(new int[]{i,Integer.parseInt(st.nextToken())});
		run();
		for(int a : answer)
			sb.append(a +" ");
	}
	
	private static void init() {
		answer = new int[numOfTower];
		stack = new Stack<int[]>();
	}
	
	private static void run() {
		Stack<int[]> tmpStack = new Stack<int[]>();
		while(!stack.isEmpty()) {
			while(!tmpStack.isEmpty() && tmpStack.peek()[1] <= stack.peek()[1]) {//tmpstack의 맨 앞보다 작은 타워 만날 때 까지 tmpstack을 뺀다.
				int[] out = tmpStack.pop();
				answer[out[0]] = stack.peek()[0] + 1;
			}
			tmpStack.add(stack.pop());
			while(!stack.isEmpty() && tmpStack.peek()[1] > stack.peek()[1])//내 앞의 것이 나보다 작을 경우 tmpstack에 넣는다.
				tmpStack.add(stack.pop());
		}
	}
}
