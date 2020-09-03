//Main idea: bottom up dp
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb= new StringBuilder();

	
	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		int S = in.nextInt();
		int[] cache = new int[2000];
		Arrays.fill(cache, Integer.MAX_VALUE);
		cache[1] = 0;
		dp(cache, S);
		System.out.println(cache[S]);
	}
	
	static void dp(int[] cache, int num) {
		for(int i = 1; i <= num ; i++) {
			int cnt = cache[i];
			for(int j = i; cache[num] >= cnt + j-num; j += i) {
				cnt ++;
				if(cache[j] <= cnt) 
					continue;
				int t = j;
				int tmp = cnt;
				while(cache[t] > tmp) 
					cache[t--] = tmp++;
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
