//Main idea: BFS
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		int[] map = new int[101];
		int[] cache = new int[101];
		for (int i = 1; i < 101; i++) {
			map[i] = i;
			cache[i] = 987654321;
		}
		int N, M;
		N = in.nextInt();
		M = in.nextInt();
		for (int i = 0; i < N + M; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			map[a] = b;
		}
		cache[1] = 0;
		dfs(map, cache);
		System.out.println(cache[100]);
	}

	static void dfs(int[] map, int[] cache) {
		Queue<int[]> que = new LinkedList<int[]>();
		que.add(new int[] { 1, 0 });// idx, cnt
		while (!que.isEmpty()) {
			int[] now = que.poll();
			int idx = now[0];
			int cnt = now[1];
			for (int i = 1; i < 7; i++) {
				int next = idx + i;
				while(next != map[next]) next = map[next];
				if (cache[next] <= cnt + 1)
					continue;
				cache[next] = cnt + 1;
				if(next == 100) 
					return;
				que.add(new int[] { next, cnt + 1 });
			}
		}
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
