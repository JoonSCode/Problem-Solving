//Main idea: 위상정렬, 데이터 크기에 신경써서
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int N, M;
	private static Map<Integer, ArrayList<Integer>> map;
	private static int[] weightOfStudent;
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		input();
		run();
		System.out.println(sb.toString());
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new HashMap<Integer, ArrayList<Integer>>();
		weightOfStudent = new int[N];
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(in.readLine(), " ");
			int from = Integer.parseInt(st.nextToken()) - 1;
			int to = Integer.parseInt(st.nextToken()) - 1;
			if(map.containsKey(from))
				map.get(from).add(to);
			else {
				ArrayList<Integer> tmp = new ArrayList<Integer>();
				tmp.add(to);
				map.put(from, tmp);
			}
			weightOfStudent[to]++;
		}
	}

	private static void run() {
		Queue<Integer> que = new LinkedList<Integer>();
		refreshQueue(que);
		while(!que.isEmpty()) {
			int from = que.poll();
			sb.append(from + 1);
			sb.append(" ");
			refreshWeight(from);
			refreshQueue(que);
		}
	}
	
	private static void refreshQueue(Queue<Integer> que) {
		for(int i = 0; i < N; i++) {
			if(weightOfStudent[i] != 0) continue;
			que.add(i);
			weightOfStudent[i] = -1;
		}
	}
	
	private static void refreshWeight(int from) {
		ArrayList<Integer> adjList = map.get(from);
		if(adjList == null) return;
		for(int a: adjList) 
			weightOfStudent[a]--;
	}
}
