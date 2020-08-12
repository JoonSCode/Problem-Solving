//Main idea: 
import java.io.*;
import java.util.*;

public class Main {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static StringBuilder sb = new StringBuilder();

	private static int N, M;

	public static void main(String[] args) throws IOException {
		test();
	}

	private static void test() throws IOException {
		input();
		boolean[] isVisited = new boolean[N + 1];
		int[] arr = new int[M];
		run(arr, 0);
		System.out.println(sb.toString());
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
	}

	private static void run(int[] arr, int cnt) {
		if (cnt == M) {
			for (int a : arr) {
				sb.append(a);
				sb.append(" ");
			}
			sb.append("\n");
			return;
		}
		for (int i = 1; i <= N; i++) {
			arr[cnt] = i;
			run(arr, cnt + 1);
		}
	}
}
