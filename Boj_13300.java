//Main idea: 그리디
import java.io.*;
import java.util.*;

public class Boj_13300 {
	private static InputReader in = new InputReader(System.in);
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws NumberFormatException, IOException {
		int N, K;
		N = in.nextInt();
		K = in.nextInt();
		int[][] student = new int[6][2];
		for(int i = 0; i < N; i++) {
			int s = in.nextInt();
			int y = in.nextInt() - 1;
			student[y][s]++;
		}
		int ans = 0;
		for(int y = 0; y < 6; y++) {
			int a = student[y][0];
			int b = student[y][1];
			ans += a/K + b/K;
			if(a%K != 0) ans++;
			if(b%K != 0) ans++;
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
