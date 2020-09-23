//Main idea: 윈도우슬라이드, 
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
		int N,K;
		N = in.nextInt();
		K = in.nextInt();
		int[]data = new int[N];
		int answer = 0;
		int sum = 0;
		for(int i = 0; i < N; i++) 
			data[i] = in.nextInt();
		for(int i = 0; i < K; i++)
			sum += data[i];
		answer = sum;
		for(int i = K; i < N; i++) {
			sum += data[i] - data[i-K];
			answer = Math.max(answer, sum);
		}
		System.out.println(answer);
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
