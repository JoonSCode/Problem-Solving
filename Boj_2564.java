//Main idea: 중복 검색 
import java.io.*;
import java.util.*;

public class Main {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		test();
	}

	static int[] cache, arr;
	private static void test() throws NumberFormatException, IOException {
		int N = in.nextInt();
		arr = new int[N];
		for (int i = 0; i < N; i++)
			arr[i] = in.nextInt();
		int ans = 0;
		for(int i = 0; i < N; i++) {
			int tmp= down(i);
			ans = Math.max(ans, tmp);
			i += tmp - 1;
		}
		
		for(int i = 0; i < N; i++) {
			int tmp= up(i);
			ans = Math.max(ans, tmp);
			i += tmp - 1;
		}
		System.out.println(ans);
	}
	
	static int up(int idx) {
		int num = arr[idx];
		int cnt = 0;
		while(idx != arr.length && arr[idx] >= num){
			num = arr[idx++];
			cnt++;
		}
		return cnt;
	}

	static int down(int idx) {
		int num = arr[idx];
		int cnt = 0;
		while(idx != arr.length && arr[idx] <= num){
			num = arr[idx++];
			cnt++;
		}
		return cnt;
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
