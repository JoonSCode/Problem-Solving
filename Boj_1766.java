//Main idea : 위상정렬
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int numOfProblem, numOfInfo;
	private static int[] weightOfProblem;
	private static ArrayList<ArrayList<Integer>> nextProblem;
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		run();
		System.out.println(sb.toString());
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine()," ");
		numOfProblem = Integer.parseInt(st.nextToken());
		numOfInfo = Integer.parseInt(st.nextToken());
		weightOfProblem = new int[numOfProblem];
		nextProblem = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < numOfProblem; i++) 
			nextProblem.add(new ArrayList<Integer>());
		for(int i = 0; i < numOfInfo; i++) {
			st = new StringTokenizer(in.readLine()," ");
			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			nextProblem.get(a).add(b);
			weightOfProblem[b]++;
		}
	}

	private static void run() {
		Queue<Integer> que = new LinkedList<Integer>();
		refreshQue(que);
		while(!que.isEmpty()) {
			int problem = que.poll();
			sb.append(problem + 1);
			sb.append(" ");
			refreshWeight(problem);
			refreshQue(que);
		}
	}
	
	private static void refreshQue(Queue<Integer> que) {
		for(int i = 0; i < numOfProblem; i++) {
			if(weightOfProblem[i] != 0) continue;
			que.add(i);
			weightOfProblem[i] = -1;
			break;
		}
	}
	
	private static void refreshWeight(int problem) {
		for(int a : nextProblem.get(problem))
			weightOfProblem[a] --;
	}
}
