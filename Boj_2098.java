//Main idea: 외판원 순회는 싸이클이 존재하는 경우이므로 어디서 시작해도 같다.
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
		int answer = Integer.MAX_VALUE;
		int numOfCity = in.nextInt();
		int[][] costArr = new int[numOfCity][numOfCity];
		int[][] cache = new int[numOfCity][(1 << numOfCity)];
		for (int y = 0; y < numOfCity; y++) {
			for (int x = 0; x < numOfCity; x++)
				costArr[y][x] = in.nextInt();
		}
		
		answer = Math.min(answer, dp(cache, costArr, 0, 1<<0, 0));

		System.out.println(answer);
	}
	
	static int dp(int[][] cache, int[][] costArr, int start, int selected, int now) {
		if(cache[now][selected] != 0) return cache[now][selected];
		if(selected == (1<<cache.length) - 1) 
			return costArr[now][start];
		
		int val = Integer.MAX_VALUE;
		for(int next = 0; next < cache.length; next ++) {
			if((selected & (1<<next)) != 0 || costArr[now][next] == 0) continue;
			int tmp =  dp(cache, costArr, start, (selected | (1 << next)), next);
			if(tmp == 0 || tmp == Integer.MAX_VALUE) continue;
				val = Math.min(val, costArr[now][next] + tmp);
		}
		return cache[now][selected] = val;
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
