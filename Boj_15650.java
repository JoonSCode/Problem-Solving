//Main idea: 조합
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
		run(isVisited, arr, 0, 1);
		System.out.println(sb.toString());
	}

	private static void input() throws IOException {
		st = new StringTokenizer(in.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
	}

	private static void run(boolean[] isVisited, int[] arr, int cnt, int idx) {
		if (N - idx + 1 < M - cnt)
			return;
		if (cnt == M) {
			for (int a : arr) {
				sb.append(a);
				sb.append(" ");
			}
			sb.append("\n");
			return;
		}
		for (int i = idx; i <= N; i++) {
			if (isVisited[i])
				continue;
			isVisited[i] = true;
			arr[cnt] = i;
			run(isVisited, arr, cnt + 1, i + 1);
			isVisited[i] = false;
		}
	}
}
