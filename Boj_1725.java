//Main idea: 스택을 이용한 히스토그램 해결
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
		int N, ans;
		N = in.nextInt();
		ans = 0;
		Stack<Integer> st = new Stack<Integer>();
		int[] block = new int[N];
		for (int i = 0; i < N; i++) {
			block[i] = in.nextInt();
			while (!st.isEmpty() && block[st.peek()] > block[i]) {
				int top = st.pop();
				int left = -1;
				if (!st.isEmpty())
					left = st.peek();
				ans = Math.max(ans, (i - left - 1) * block[top]);
			}
			st.push(i);
		}
		while (!st.isEmpty()){
			int top = st.pop();
			int left = -1;
			if (!st.isEmpty())
				left = st.peek();
			ans = Math.max(ans, (N - 1 - left) * block[top]);
		}
		System.out.println(ans);
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
