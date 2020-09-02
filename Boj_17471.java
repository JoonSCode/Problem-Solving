//Main idea: 백트래킹, 각각의 기능들을 나누어 
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	static int ans, N;
	static int[] populations;
	static ArrayList<Integer>[] adjList;
	static final int INF = Integer.MAX_VALUE;
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		input();
		comb(new boolean[N], 0, 0);
		System.out.println((ans == INF) ? -1 : ans);
	}

	static void input() throws IOException {
		N = in.nextInt();
		populations = new int[N];
		adjList = new ArrayList[N];
		ans = INF;
		for(int i = 0; i < N; i++)
			populations[i] = in.nextInt();
		for(int i = 0; i < N; i++) {
			ArrayList<Integer> tmp = new ArrayList<Integer>();
			int size = in.nextInt();
			for(int a = 0; a < size; a++)
				tmp.add(in.nextInt() - 1);
			adjList[i] = tmp;
		}
	}
	
	static void comb(boolean[] isGroup, int idx, int cnt) {
		if(cnt != 0)
			ans = Math.min(ans, getVal(isGroup, cnt));
		if(cnt == N-1) 
			return;
		for(int i = idx; i < N; i++) {
			isGroup[i] = true;
			comb(isGroup, i+1, cnt+1);
			isGroup[i] = false;
		}
	}
	
	static boolean isPossible(boolean[] isGroup, int cnt) {
		Queue<Integer> que = new LinkedList<Integer>();
		int size = 1;
		boolean[] isVisited = new boolean[N];
		for(int i = 0; i < N; i++) {
			if(isGroup[i]) {
				isVisited[i] = true;
				que.add(i);
				break;
			}
		}
		
		while(!que.isEmpty()) {
			int now = que.poll();
			for(int next : adjList[now]) {
				if(isGroup[next] != isGroup[now] || isVisited[next]) continue;
				isVisited[next] = true;
				que.add(next);
				size++;
			}
		}
		if(size != cnt) return false;
		
		for(int i = 0; i < N; i++) {
			if(!isGroup[i]) {
				isVisited[i] = true;
				que.add(i);
				break;
			}
		}
		size++;
		while(!que.isEmpty()) {
			int now = que.poll();
			for(int next : adjList[now]) {
				if(isGroup[next] != isGroup[now] || isVisited[next]) continue;
				isVisited[next] = true;
				que.add(next);
				size++;
			}
		}
		
		if(size != N) return false;
		
		
		return true;
	}
	
	static int getVal(boolean[] isGroup, int cnt) {
		if(!isPossible(isGroup, cnt)) 
			return INF;
		int sum = 0;
		for(int i = 0; i < N; i++) {
			if(isGroup[i]) sum += populations[i];
			else
				sum -= populations[i];
		}
		return Math.abs(sum);
	}
}

class InputReader extends BufferedReader {
	private StringTokenizer st;

	public InputReader(InputStream in) {
		super(new InputStreamReader(in));
	}

	public int nextInt() throws IOException {
		if (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		return Integer.parseInt(st.nextToken());
	}

	public int nextInt(String delimiter) throws IOException {
		if (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine(), delimiter);
		return Integer.parseInt(st.nextToken());
	}
}
